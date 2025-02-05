#include <stdio.h>
#include <stdlib.h>


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

void print_lower_and_previous(element **first_element)
{
    element *lower_element = *first_element;
    element **prev_lower_element = first_element;

    for (element *i = *first_element; i && i->next; i = i->next)
    {
        if (i->next->value < lower_element->value)
        {
            *prev_lower_element = i;
            lower_element = i->next;
        }
    }

    printf("Previous lower element value: %d\n", (*prev_lower_element)->value);
    printf("Lower element value: %d\n", lower_element->value);
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
    print_lower_and_previous(&first_element);
    print(first_element);
}