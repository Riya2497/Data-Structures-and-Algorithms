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

void Inorder(struct Node* temp)
{
    if(temp)
    {
        Inorder(temp->left);
        printf("%d_",temp->val);
        Inorder(temp->right);
    }
}

void Preorder(struct Node* temp)
{
    if(temp)
    {
        printf("%d_",temp->val);
        Preorder(temp->left);
        Preorder(temp->right);
    }
}

void Postorder(struct Node* temp)
{
    if(temp)
    {
        Postorder(temp->left);
        Postorder(temp->right);
        printf("%d_",temp->val);
    }
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

int main(void) 
{
	struct Node* root=NULL;
	
	int n;
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
	
	Preorder(root);
	printf("\n");
	Inorder(root);
	printf("\n");
	Postorder(root);

	return 0;
}

