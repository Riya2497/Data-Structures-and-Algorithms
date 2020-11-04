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

void remove_greater()
{
    struct Node* ptr = head;
    
    struct Node* ptr1 = NULL;
    
    while(ptr->next!=NULL)
    {
        if(ptr==head && ptr->data < ptr->next->data)
        {
            struct Node* temp = head; 
            head = head->next; 
  
            free(temp);
            ptr = head;
            continue;
        }
        else 
        {
            while(ptr->next && ptr->next->next && ptr->next->data < ptr->next->next->data)
            {
                ptr1 = ptr->next;
                ptr->next =  ptr->next->next;
            }
            
        }
        ptr = ptr->next;
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
    
    head->data = 10;
    head->next = second;
    
    second->data = 12;
    second->next = third;
    
    third->data = 15;
    third->next = fourth;
    
    fourth->data = 20;
    fourth->next = fifth;
    
    fifth->data = 5;
    fifth->next = sixth;
    
    sixth->data = 16;
    sixth->next = seventh;
    
    seventh->data = 25;
    seventh->next = eighth;
    
    eighth->data = 8;
    eighth->next = NULL;
    
    printList();
    printf("\n");
    
    remove_greater();
    
    printList();
	
	return 0;
}