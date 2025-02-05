#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *ptr1 = (int *)malloc(sizeof(int));
    *ptr1 = 1;
    int *ptr2 = (int *)malloc(sizeof(int));
    *ptr2 = 2;
    int **ptrx = &ptr2;

    printf("Address of ptr1 itself: %p\n", (void*)&ptr1);
    printf("Value of ptr1 (Address stored in ptr1): %p\n", (void*)ptr1);

    printf("Address of ptr2 itself: %p\n", (void*)&ptr2);
    printf("Value of ptr2 (Address stored in ptr2): %p\n", (void*)ptr2);

    printf("Address of ptrx itself: %p\n", (void*)&ptrx);
    printf("Value of ptrx (Address stored in ptrx): %p\n", (void*)ptrx);

    printf("*ptr1: %d, ptr2: %d\n", *ptr1, *ptr2);

    free(ptr2);
    *ptrx = ptr1;

    printf("Value of ptrx (Address stored in ptrx): %p\n", (void*)ptrx);
    printf("Value of ptr1 (Address stored in ptr1): %p\n", (void*)ptr1);
    printf("Value of ptr2 (Address stored in ptr2): %p\n", (void*)ptr2);
    printf("Address of ptr2 itself: %p\n", (void*)&ptr2);
    printf("*ptr1: %d, ptr2: %d\n", *ptr1, *ptr2);
    
    return 0;
}
