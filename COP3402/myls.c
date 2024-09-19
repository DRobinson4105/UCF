#include <fcntl.h>
#include <unistd.h>
// #include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <inttypes.h>

// returns the number of entries in a directory
int dir_size(const char *path);

int main(int argc, char **argv) {
    // if directory path is not provided
    if (argc < 2) {
        fprintf(stderr, "USAGE: %s path\n", argv[0]);
        exit(1);
    }

    char *path = argv[1];
    struct stat statbuf;

    if (stat(path, &statbuf) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    
    DIR *dirp = opendir(path);

    if (dirp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent* curdir;

    // loop through entries in provided directory path
    while ((curdir = readdir(dirp)) != NULL) {
        char filepath[1024];

        // concatenate provided directory path with entry name
        snprintf(filepath, sizeof(filepath), "%s/%s", path, curdir->d_name);
        
        if (stat(filepath, &statbuf) == -1) {
            perror("stat error");
            continue;
        }

        // print entry name
        printf("%16.16s\t", curdir->d_name);

        // print number of hard links
        // printf("%hu\t", statbuf.st_nlink);
        printf("%" PRIdMAX "\t", (intmax_t)statbuf.st_nlink);
        
        // print the type of file
        switch (statbuf.st_mode & S_IFMT) {
        case S_IFREG:
            printf("REG\t");
            break;
        case S_IFDIR:
            printf("DIR\t");
            break;
        case S_IFSOCK:
            printf("SOCK\t");
            break;
        case S_IFLNK:
            printf("LNK\t");
            break;
        case S_IFBLK:
            printf("BLK\t");
            break;
        case S_IFCHR:
            printf("CHR\t");
            break;
        case S_IFIFO:
            printf("FIFO\t");
            break;
        default:
            printf("UNKNOWN\t");
            break;
        }

        // if the current entry is a directory, the size is the number of entries
        if ((statbuf.st_mode & S_IFMT) == S_IFDIR) {
            // count the number of entries in 
            int size = dir_size(filepath);

            if (size == -1) {
                perror("dir");
                exit(EXIT_FAILURE);
            }

            printf("%d\t", size);
        } else {
            // otherwise, the size is from stat()
            printf("%" PRIdMAX "\t", (intmax_t)statbuf.st_size);
        }

        // if the file is a regular file, display a preview of the text
        if ((statbuf.st_mode & S_IFMT) == S_IFREG) {
            int fd = open(filepath, O_RDONLY);
            if (fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }

            const int BUFSIZE = 16;
            char buf[BUFSIZE];
            int bytes = read(fd, buf, BUFSIZE);
            if (bytes == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            // replace any non-printable or non-ASCII characters with spaces
            for (int i = 0; i < bytes; i++) {
                printf("%c", buf[i] < 32 || buf[i] > 126 ? ' ' : buf[i]);
            }
        }
        printf("\n");
    }


    if (closedir(dirp) == -1) {
        perror("closedir");
        exit(EXIT_FAILURE);
    }
}

int dir_size(const char *path) {
    DIR *dirp = opendir(path);
    if (dirp == NULL) {
        return -1;
    }

    struct dirent *cur;
    int size = 0;

    while ((cur = readdir(dirp)) != NULL) {
        size++;
    }

    if (closedir(dirp)) {
        return -1;
    }

    return size;
}