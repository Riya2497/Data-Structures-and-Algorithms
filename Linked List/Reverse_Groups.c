#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};



void printList(struct Node* head)
{
    struct Node* temp = head;
    
    while(temp!=NULL)
    {
    printf("%d->", temp->data);
    temp = temp->next;
    }
    printf("NULL");
}

struct Node* reverse_groups(struct Node* head, int k)
{
    struct Node* curr = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;
    
    int count = 0;
    
    while(curr!=NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        
        count++;
    }
    
    if(next!=NULL)
    head->next = reverse_groups(next, k);
    
    return prev;
      
}

int main(void) 
{
    int k;
    scanf("%d\n", &k);
    
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    struct Node* fifth = NULL;
    struct Node* sixth = NULL;
    struct Node* seventh = NULL;
    struct Node* eighth = NULL;
    struct Node* ninth = NULL;
    struct Node* tenth = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));
    sixth = (struct Node*)malloc(sizeof(struct Node));
    seventh = (struct Node*)malloc(sizeof(struct Node));
    eighth = (struct Node*)malloc(sizeof(struct Node));
    ninth = (struct Node*)malloc(sizeof(struct Node));
    tenth = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 1;
    head->next = second;
    
    second->data = 2;
    second->next = third;
    
    third->data = 3;
    third->next = fourth;
    
    fourth->data = 4;
    fourth->next = fifth;
    
    fifth->data = 5;
    fifth->next = sixth;
    
    sixth->data = 6;
    sixth->next = seventh;
    
    seventh->data = 7;
    seventh->next = eighth;
    
    eighth->data = 8;
    eighth->next = ninth;
    
    ninth->data = 12;
    ninth->next = tenth;
    
    tenth->data = 7;
    tenth->next = NULL;
    
    printList(head);
    printf("\n");
    
    head = reverse_groups(head, k);
    
    printList(head);
	
	return 0;
}