#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
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
        return createNode(newNode);
    
    if(temp->val > newNode)
        temp->left = insert(temp->left,newNode);
    else 
        temp->right = insert(temp->right,newNode);
        
    return temp;
}

void DFS(struct Node* root)
{
    if(!root)
        return;
        
    printf("%d ",root->val);
    DFS(root->left);
    DFS(root->right);
}

int main(void) 
{
	struct Node* root=NULL;
	int n,c;
	
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
	    scanf("%d",&arr[i]);
	    if(root==NULL)
	        root=insert(root, arr[i]);
	    else 
	        insert(root, arr[i]);
	}
	
	DFS(root);
	
    return 0;
}
