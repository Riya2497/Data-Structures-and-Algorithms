#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* creatNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* temp, int newNode)
{
    if(!temp)
    return creatNode(newNode);
    
    if(temp->val>newNode)
        temp->left = insert(temp->left, newNode);
    else
        temp->right = insert(temp->right, newNode);
        
    return temp;
}

bool printAncestors(struct Node* root, int target) 
{ 
  if (root == NULL) 
     return false; 
  
  if (root->val == target) 
     return true; 
  
  if ( printAncestors(root->left, target) || printAncestors(root->right, target) ) 
  { 
    printf("%d ", root->val); 
    return true; 
  } 
  
  return false; 
} 

int main(void) 
{
	struct Node* root = NULL;
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        if(root==NULL)
        root = insert(root, arr[i]);
        else
        insert(root, arr[i]);
    }
    
    int key;
    scanf("%d", &key);
    
    printAncestors(root, key);

}

