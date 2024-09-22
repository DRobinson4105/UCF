#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <inttypes.h>

int main(int argc, char **argv) {
    char *path;

    // if directory path is not provided, set it to the current working directory
    if (argc < 2) {
        path = ".";
    } else {
        path = argv[1];
    }

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
        char filepath[FILENAME_MAX];

        // concatenate provided directory path with entry name
        snprintf(filepath, sizeof(filepath), "%s/%s", path, curdir->d_name);
        
        if (stat(filepath, &statbuf) == -1) {
            perror("stat");
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
            // count the number of entries in the directory
            DIR *dirp = opendir(filepath);

            if (dirp == NULL) {
                perror("opendir");
                exit(EXIT_FAILURE);
            }

            struct dirent *cur;
            int size = 0;

            while ((cur = readdir(dirp)) != NULL) {
                size++;
            }

            if (closedir(dirp)) {
                perror("closedir");
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
            int numBytes = read(fd, buf, BUFSIZE);
            if (numBytes == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            // replace any non-printable or non-ASCII characters with spaces
            for (int i = 0; i < numBytes; i++) {
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