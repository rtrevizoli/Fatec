#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *product;
    struct node *next;
} node;

void print_queue(node *queue)
{
    printf("1\n");
    for (node *p = queue; p; p = queue->next)
    {
        printf("Gay => %s\n", p->product);
    }
    printf("2\n");
}

node *create_node(char* product)
{
    node *new_node = (node *)malloc(sizeof(node));

    new_node->next = NULL;
    new_node->product = (char *)malloc(strlen(product) + 1);

    strcpy(new_node->product, product);

    return new_node;
}

void add_node(node *queue, char *product)
{
    printf("add1\n");
    if (queue)
    {
        return;
    }
    printf("add2\n");

    node *p = NULL;
    for (p = queue; p->next == NULL; p = p->next) { printf("gelo\n"); };
    printf("add3\n");
    
    p->next = create_node(product);
    printf("add4\n");
}

int main()
{
    printf("11\n");
    node* queue = NULL;

    printf("12\n");
    add_node(queue, "Caique");

    printf("13\n");
    print_queue(queue);

    
    return 0;
}