#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

struct Node* head = NULL;

void printList()
{
    struct Node* temp = head;
    
    while(temp!=NULL)
    {
    printf("%d->", temp->data);
    temp = temp->next;
    }
    printf("NULL");
}

void delete_duplicates()
{
    struct Node* ptr1;
    struct Node* ptr2;
    struct Node* dup;
    
    ptr1 = head;
    
    while(ptr1!=NULL && ptr1->next!=NULL)
    {
        ptr2 = ptr1;
        
        while(ptr2->next!=NULL)
        {
            if(ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
            ptr2 = ptr2->next;
        }
        
        ptr1 = ptr1->next;
    }
}

int main(void) 
{
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    struct Node* fifth = NULL;
    struct Node* sixth = NULL;
    struct Node* seventh = NULL;
    struct Node* eighth = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));
    sixth = (struct Node*)malloc(sizeof(struct Node));
    seventh = (struct Node*)malloc(sizeof(struct Node));
    eighth = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 20;
    head->next = second;
    
    second->data = 18;
    second->next = third;
    
    third->data = 15;
    third->next = fourth;
    
    fourth->data = 20;
    fourth->next = fifth;
    
    fifth->data = 6;
    fifth->next = sixth;
    
    sixth->data = 18;
    sixth->next = seventh;
    
    seventh->data = 5;
    seventh->next = eighth;
    
    eighth->data = 3;
    eighth->next = NULL;
    
    printList();
    printf("\n");
    
    delete_duplicates();
    
    printList();
	
	return 0;
}

