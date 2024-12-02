#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char *name;
    struct student *next;
} student;

void print(student *queue)
{
    printf("Printing...\n");
    for (student *p = queue; p; p = p->next)
    {
        printf("student => %s\n", p->name);
    }
    printf("Printed\n");
}

student *create_student(char *name)
{
    student *new_student = (student *)malloc(sizeof(student));

    new_student->next = NULL;
    new_student->name = (char *)malloc(strlen(name) + 1);

    strcpy(new_student->name, name);

    return new_student;
}

student *free_student(student *queue)
{
    free(queue->name);
    free(queue);
}

void enqueue(student **first_student, student **last_student, char *name)
{
    student *new_student = create_student(name);

    if (*first_student == NULL && *last_student == NULL)
    {
        *first_student = new_student;
        *last_student = new_student;
        return;
    }

    (*last_student)->next = new_student;
    *last_student = new_student;
}

void dequeue(student **first_student)
{
    if (*first_student == NULL)
    {
        printf("Queue is empty, cannot dequeue\n");
        return;
    }

    printf("Validating => %s\n", (*first_student)->name);
    student *aux_student = (*first_student)->next;
    free_student(*first_student);
    *first_student = aux_student;
}

int main()
{
    student *first_student = NULL;
    student *last_student = NULL;

    enqueue(&first_student, &last_student, "Ruth");
    enqueue(&first_student, &last_student, "Gabriel");
    enqueue(&first_student, &last_student, "Isaque");
    enqueue(&first_student, &last_student, "Pablo");
    enqueue(&first_student, &last_student, "Naiara");
    enqueue(&first_student, &last_student, "Paloma");
    enqueue(&first_student, &last_student, "Juan");
    enqueue(&first_student, &last_student, "Carla");
    enqueue(&first_student, &last_student, "Cesar");
    enqueue(&first_student, &last_student, "Joao");

    print(first_student);

    dequeue(&first_student);

    print(first_student);

    return 0;
}