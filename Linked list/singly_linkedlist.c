#include <stdio.h>
#include <stdlib.h>

#define NULL 0

struct ListNode
{
    int data;
    struct ListNode *next;
};

typedef struct ListNode LN;

LN *head;

void init()
{
    head = NULL;
}

void print_list()
{
    LN *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

LN *search(int key)
{
    LN *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void insert_first(int item)
{
    LN *new_node = (LN *)malloc(sizeof(LN));
    new_node->data = item;
    new_node->next = head;
    head = new_node;
}

void delete_first()
{
    if (head == NULL)
        return;
    LN *temp = head;
    head = head->next;
    free(temp);
}

void insert_last(int item)
{
    // write your code here
    if (head == NULL)
        insert_first(item);
    else
    {
        LN *new_node = (LN *)malloc(sizeof(LN));
        //create a node and assign value
        new_node->data = item;
        LN *temp = head;
        //traverse to the last node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        //link new_node to null and last-node to new_node
        new_node->next = NULL;
        temp->next = new_node;
    }
}

void delete_last()
{
    // write your code here
    //corner cases
    if (head == NULL)
    {
        printf("There's nothing to delete in this list");
        return;
    }
    else if (head->next == NULL)
    {
        delete_first();
    }

    LN *temp = head;
    //traverse to the node before last node
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    LN *fre = temp->next;
    temp->next = NULL;
    free(fre);
}

void insert_after(int olditem, int newitem)
{
    // write your code here
    LN *new_node = (LN *)malloc(sizeof(LN));
    LN *temp;
    new_node->data = newitem;
    //traverse to match olditem value
    for (temp = head; temp != NULL;)
    {
        if (temp->data == olditem)
        {
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
        temp = temp->next;
    }
    // if not matched, return
    return;

    // I first tried this function with while loop but got segmentation error
    // while (temp->data != olditem && temp != NULL)
    // {
    //     temp = temp->next;
    // }
    // //handling corner case

    // //linking the node
    // if (temp != NULL)
    // {
    //     new_node->next = temp->next;
    //     temp->next = new_node;
    //     return;
    // }
}

void delete_after(int olditem)
{
    // write your code here
    LN *temp;
    LN *FREE;
    if (head == NULL)
        return;
    //traverse to match olditem value
    for (temp = head; temp != NULL;)
    {
        if (temp->data == olditem)
        {
            FREE = temp->next;
            temp->next = temp->next->next;
            free(FREE);
            return;
        }
        temp = temp->next;
    }

    return;
}

void delete_item(int item)
{
    // write your code here
    LN *temp;
    LN *FREE;
    if (head == NULL)
        return;
    // if item is in the first node delete_first() handles the call
    if (head->data == item)
    {
        delete_first();
        //segmentation error if do not return;
        return;
    }
    // travarsing nodes to match the item value
    for (temp = head; temp != NULL;)
    {
        //if value matches...
        if (temp->next->data == item)
        {
            FREE = temp->next;
            temp->next = temp->next->next;
            free(FREE);
            return;
        }
        temp = temp->next;
    }

    return;
}

int main()
{
    init();
    insert_first(2);
    insert_first(5);
    insert_first(7);
    insert_first(3);
    insert_first(13);
    insert_first(9);
    insert_first(11);
    insert_last(60);
    insert_last(90);

    delete_last();
    insert_after(9, 80);
    delete_after(88);
    delete_item(11);
    print_list();
    // delete_first();
    // print_list();
    // delete_first();
    // print_list();
    // delete_first();
    // print_list();
    // delete_first();
    // print_list();
    // delete_first();
    // print_list();
    // delete_first();
    // print_list();
    // delete_first();
    // print_list();
    // delete_first();
    // print_list();

    // insert_first(6);
    // print_list();

    return 0;
}
