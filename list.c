#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


// Represents a node
typedef struct node
{
    int number;
    struct node *next;
}
node;

// Prototypes
void freeList(struct node* list);
void insertSortedNode(struct node* insertedNode, struct node* list);
void printLinkedList(struct node* list);


int main(void)
{
    node *list = NULL;

    // first node
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;

    //list = n;
    insertSortedNode(n, list);

    printLinkedList(list);


    // second node
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 5;
    n->next = NULL;
    insertSortedNode(n, list);

    // third
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        // Free both of our other nodes
        free(list->next);
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    insertSortedNode(n, list);

    printLinkedList(list);

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        freeList(list);
    }
    n->number = 8;
    n->next = NULL;


    insertSortedNode(n, list);
    printLinkedList(list);

    freeList(list);
}

void freeList(struct node *list)
{
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}

void insertSortedNode(struct node* insertedNode, struct node* list)
{
    if (!list)
    {
        printf("List is empty, node starting\n");
        list = insertedNode;
        return;
    }

    for(node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        if (tmp->next == NULL)
        {
            tmp->next = insertedNode;
            break;
        }
        if (tmp->next->number >= insertedNode->number)
        {
            insertedNode->next = tmp->next;
            tmp->next = insertedNode;
            break;
        }
    }
}

void printLinkedList(struct node* list)
{
    printf("List printing\n");
    for(node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }
}
