#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element
{
    int value;
    struct element *next;
} element;

void print(element *list)
{
    printf("Printing...\n");
    for (element *p = list; p; p = p->next)
    {
        if (p->next == NULL)
        {
            printf("%d\n", p->value);
            printf("Printed\n\n");
            return;
        }

        printf("%d => ", p->value);
    }
}

element *create_element(int value)
{
    element *new_element = (element *)malloc(sizeof(element));

    new_element->value = value;
    new_element->next = NULL;

    return new_element;
}

void add(element **first_element, element **last_element, int value)
{
    element *new_element = create_element(value);

    if (*first_element == NULL && *last_element == NULL)
    {
        *first_element = new_element;
        *last_element = new_element;
        return;
    }

    (*last_element)->next = new_element;
    *last_element = new_element;
}

void swap_elements(element **first_element, element *prev_x, element *x, element *prev_y, element *y)
{
    // Skipping in case current and lower is equal;
    if (x == y) return;

    // Swapping prev next, case prev is null set element as head
    if (prev_x) prev_x->next = y;
    else *first_element = y;

    if (prev_y) prev_y->next = x;
    else *first_element = x;

    // Swapping elements
    element *temp = x->next;
    x->next = y->next;
    y->next = temp;
}

void sort(element **first_element)
{
    if (*first_element == NULL) return;

    element *prev_lower_element = NULL;
    element *lower_element = NULL;

    for (element *i = *first_element, *prev_i = NULL; i && i->next; prev_i = i, i = i->next)
    {
        lower_element = i;
        prev_lower_element = prev_i;

        for (element *j = i->next, *prev_j = i; j; prev_j = j, j = j->next)
        {
            printf("[%d][%d]\n", i->value, j->value);

            if (j->value < lower_element->value)
            {
                lower_element = j;
                prev_lower_element = prev_j;
            }
        }

        if (i != lower_element)
        {
            printf("\nBefore swap\n");
            printf("*i -> %d\n", i->value);
            printf("*lower_element -> %d\n", lower_element->value);

            swap_elements(first_element, prev_i, i, prev_lower_element, lower_element);
            
            printf("After swap\n");
            printf("*i -> %d\n", i->value);
            printf("*lower_element -> %d\n", lower_element->value);

            i = lower_element;

            printf("After reset i\n");
            printf("*i -> %d\n", i->value);
            printf("*lower_element -> %d\n", lower_element->value);

        }
    }
}

int main()
{
    element *first_element = NULL;
    element *last_element = NULL;

    add(&first_element, &last_element, 64);
    add(&first_element, &last_element, 25);
    add(&first_element, &last_element, 12);
    add(&first_element, &last_element, 22);
    add(&first_element, &last_element, 11);

    print(first_element);
    sort(&first_element);
    print(first_element);
}