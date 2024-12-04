#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book
{
    char *title;
    struct book *next;
} book;

void print(book *stack)
{
    printf("Printing...\n");
    for (book *p = stack; p; p = p->next)
    {
        printf("book => %s\n", p->title);
    }
    printf("Printed\n\n");
}

book *create_book(char *title)
{
    book *new_book = (book *)malloc(sizeof(book));

    new_book->next = NULL;
    new_book->title = (char *)malloc(strlen(title) + 1);

    strcpy(new_book->title, title);

    return new_book;
}

book *free_book(book *stack)
{
    free(stack->title);
    free(stack);
}

void push(book **first_book, char *title)
{
    book *new_book = create_book(title);

    if (*first_book == NULL)
    {
        *first_book = new_book;
        return;
    }

    new_book->next = (*first_book);
    (*first_book)=new_book;
}

void pop(book **first_book)
{
    printf("Reading => %s\n\n", (*first_book)->title);
    book *aux_book = (*first_book)->next;
    free_book(*first_book);
    *first_book = aux_book;
}

int main()
{
    book *first_book = NULL;

    push(&first_book, "The Silmarillion");
    push(&first_book, "Unfinished Tales and The History of Middle-Earth");
    push(&first_book, "The Hobbit");
    push(&first_book, "The Fellowship of the Ring");
    push(&first_book, "The Two Towers");
    push(&first_book, "The Return of the King");

    print(first_book);

    pop(&first_book);

    print(first_book);

    return 0;
}