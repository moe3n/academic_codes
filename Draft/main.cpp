#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
    
};

struct node* head , *dummy;

// functions
void insert(int key);



struct node* createnode(int key)
{
    struct node* newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    
    if (dummy->next == NULL) {
        newnode->data= key;
        dummy->next = newnode;
        newnode->prev = dummy;
        newnode->next = NULL;
        head = newnode;
        
    }
    else
    {
        insert(key);
    }
    
    
    return newnode;
    
}

void insert(int key)
{
    int val;
    printf("enter key to search nodes\n");
    scanf("%d", &val);
    struct node* newnode,*t;
    newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    temp = head;
    
    while (temp->next!=NULL) {
        if (temp->data == key) {
            if (temp->next == NULL) {
                newnode->next = NULL;
                newnode->data = key;
                temp->next = newnode;
                newnode->prev = temp;
                
            }
            else{
                newnode->data = key;
                t = temp->next;
                newnode->next = t;
                t->prev = newnode;
                temp->next = newnode;
                newnode->prev = temp;
                
                
            }
            
        }
        else{
        newnode->next = head;
        head->prev = newnode;
        dummy->next = newnode;
        newnode->prev = dummy;
        head = newnode;
        }
        head = head->next;
    }
}




void display()
{
    struct node* temp;
    temp= dummy;
    temp = temp->next;
    printf("\n");

    while (temp!=NULL) {
        printf("%d " , temp->data);
        
        temp=temp->next;
        
    }
    printf("\n");
    
}


int main(int argc, char const *argv[]) {
    
    int key;
    int choice, c;
    dummy = (struct node*) malloc(sizeof(struct node));
    dummy->next =NULL;
    dummy->prev = NULL;
    printf("for while\n");
    scanf("%d",&c);
    while (c!=-1) {
        printf("for switch\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                
                printf(" Enter the key value\n" );
                scanf("%d",&key );
                createnode(key);
                break;
            
            case 2:
               // del();
                
            case 3:
              //  search();
                
            case 4:
                display();
                break;
            case 5:
                c = -1;
                break;
            
        }
    }
    
    
    

    return 0;
}

