#include <bits/stdc++.h> 
using namespace std; 
  
/* Linked list node */
class Node 
{ 
public: 
    int data; 
    Node* next; 
}; 

Node* newNode(int data) 
{ 
    Node* new_node = new Node(); 
    new_node->data = data; 
    new_node->next = NULL; 
    return new_node; 
} 

void push(Node** head_ref, int new_data) 
{ 
    /* allocate node */
    Node* new_node = newNode(new_data); 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
    cout << endl; 
} 

int main(void) 
{ 
    // create list 7->5->9->4->6 
    Node* first = NULL;
    push(&first, 6); 
    push(&first, 4); 
    push(&first, 9); 
    push(&first, 5); 
    push(&first, 7); 

    printList(first); 
  
    return 0; 
} 
