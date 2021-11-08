#include <stdio.h>
#include <stdlib.h>

#define NULL 0

struct ListNode
{
    int data;
    struct ListNode *next;
    struct ListNode *prev;
};

typedef struct ListNode LN;

LN *head;
LN *tail;

void init()
{
    head = NULL;
    tail = NULL;
}

void print()
{
    LN *temp = head;
    while (temp->next != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    //...
    printf("%d", temp->data);
    printf("\n");
}

void print_backward()
{
    //...
    LN *temp = tail->prev;
    printf("%d", tail->data);
    while (temp != NULL)
    {
        printf("<-%d", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

LN *search(int key)
{
    LN *temp = head;
    while (temp != NULL)
    {
        if (key == temp->data)
            break;
        temp = temp->next;
    }
    return temp;
}

void insert_first(int item)
{
    LN *new_node = (LN *)malloc(sizeof(LN));
    new_node->data = item;
    new_node->next = head;
    new_node->prev = NULL;
    if (tail == NULL)
    {
        tail = new_node;
    }
    else
    {
        head->prev = new_node;
    }
    head = new_node;
}

void insert_last(int item)
{
    LN *new_node = (LN *)malloc(sizeof(LN));
    new_node->data = item;
    new_node->prev = tail;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        tail->next = new_node;
    }
    tail = new_node;
}

void insert_at(int item, int pos)
{
    if (pos == 1)
        return insert_first(item);

    LN *temp = head;
    int counter = 1;
    while (temp != NULL)
    {
        if (counter == pos - 1)
        {
            break;
        }
        temp = temp->next;
        counter++;
    }
    if (temp == NULL)
        return;
    LN *new_node = (LN *)malloc(sizeof(LN));
    new_node->data = item;
    if (temp == tail)
    {
        tail = new_node;
    }
    else
    {
        temp->next->prev = new_node;
    }
    new_node->prev = temp;
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_first()
{
    if (head == NULL)
        return;

    LN *temp = head;
    head = head->next;
    if (head == NULL)
    {
        tail = NULL;
    }
    else
    {
        head->prev = NULL;
    }
    free(temp);
}

void delete_last()
{
    if (tail == NULL)
        return;

    LN *temp = tail;
    tail = tail->prev;
    if (tail == NULL)
    {
        head = NULL;
    }
    else
    {
        tail->next = NULL;
    }
    free(temp);
}

void delete_item(int item)
{
    // write your code here
    LN *Z = search(item);
    //IF item is in first node let delete_first() handle the op
    if (Z == head)
    {
        delete_first();
        return;
    }
    // if item is in last node let delete_last() handle the op
    else if (Z == tail)
    {
        delete_last();
        return;
    }
    // if item is found elsewhere
    else if (Z != NULL)
    {
        LN *Y = Z->next;
        LN *X = Z->prev;
        X->next = Y;
        Y->prev = X;
        free(Z);
        return;
    }
    // if item is not found, return
    return;
}

int main()
{
    init();
    insert_first(15);
    insert_first(25);
    insert_first(35);
    insert_last(45);
    insert_first(55);

    delete_item(65);
    print();
    print_backward();
    // print_backward();

    // insert_at(66, 6);
    // print();
    // print_backward();

    return 0;
}
