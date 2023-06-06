#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 20

typedef struct Student Student;
typedef struct studentVTable studentVTable;

struct Student {
    int age;
    char* name;
    const studentVTable *vtable;
};

struct studentVTable {
    void (*printAge)(Student *self);
};

void print_age(Student* student) {
    printf("%s's age is %d.\n", student->name, student->age);
}

static const studentVTable vtable_student = {
    .printAge = print_age
};

Student* studentInit(char* newName, int newAge) {
    Student* res = (Student *) malloc(sizeof(Student));
    res->name = newName;
    res->age = newAge;
    res->vtable = &vtable_student;
    return res;
}

int main() {
    char* name = (char*) malloc(sizeof(char) * MAX_LENGTH);
    int age;
    Student* newStudent;

    printf("Name: ");
    scanf("%s", name);
    printf("Age: ");
    scanf("%d", &age);
    
    newStudent = studentInit(name, age);
    newStudent->vtable->printAge(newStudent);
    return 0;
}