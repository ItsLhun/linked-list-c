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
void insertSortedNode(struct node* insertedNode, struct node** list);
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
    insertSortedNode(n, &list);

    printLinkedList(list);


    //second node
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 5;
    n->next = NULL;
    insertSortedNode(n, &list);
    printLinkedList(list);

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
    insertSortedNode(n, &list);

    printLinkedList(list);

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        freeList(list);
    }
    n->number = 8;
    n->next = NULL;


    insertSortedNode(n, &list);
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

void insertSortedNode(struct node* insertedNode, struct node** list)
{
    // this checks if this is the first node
    if (*list == NULL)
    {
        insertedNode->next = *list;
        *list = insertedNode;
        return;
    }

    for(node* tmp = *list; tmp != NULL; tmp = tmp->next)
    {
        // this checks if we are at the end, then appends the node last
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