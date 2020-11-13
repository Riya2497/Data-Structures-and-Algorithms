#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};

//struct Node* root=NULL,*ptr=NULL;

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
    if(!temp) return createNode(newNode);
    
    if(temp->val > newNode)
        temp->left = insert(temp->left,newNode);
    else 
        temp->right = insert(temp->right,newNode);
        
    return temp;
}

void deleteNode(struct Node* root)
{
    if(root)
    {
        if(root->left && !root->left->left && !root->left->right)
        {
            printf("%d ",root->left->val);
            root->left=NULL;
        }
        if(root->right && !root->right->left && !root->right->right)
        {
            printf("%d ",root->right->val);
             root->right=NULL;
        }
        
        deleteNode(root->left);
        deleteNode(root->right);
        
    }
}

void inorder_BST(struct Node* root)
{
    if(!root)
    return;
    
    inorder_BST(root->left);
    printf("%d ", root->val);
    inorder_BST(root->right);
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
	
	printf("Deleted: ");
	deleteNode(root);
	printf("\n");
	
	printf("Inorder traversal of revised tree: ");
	inorder_BST(root);
    return 0;
}
