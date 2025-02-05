#include <stdio.h>
#include <stdlib.h>

int main()
{
    int value = 10;
    int *number;
    int **p;

    printf("Address of value: %p\n", &value);
    printf("Address of *number: %p\n", &number);
    printf("Address of **p: %p\n", &p);

    printf("\n==============\n");
    printf("Case 1: int **p = &number;\n");
    printf("Assigning the address of 'number' to 'p'\n");
    printf("-------\n");
    number = &value;
    p = &number;

    printf("**p -> *number -> value\n");
    printf("%p -> %p -> %p\n",&p, &number, &value);

    printf("\n==============\n");
    printf("Case 2: int **p = number;\n");
    printf("Assigning the same memory location stored in 'number' to 'p'. In other words 'p' points to the same location of 'number'.\n");
    printf("-------\n");

    p = number;

    printf("**p -> value\n");
    printf("%p -> %p\n", &p, (void*)p);
    printf("\n");
    printf("*number -> value\n");
    printf("%p -> %p\n", &number, (void*)number);

    return 0;
}