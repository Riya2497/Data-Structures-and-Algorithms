#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};

//struct Node* root=NULL,*ptr=NULL;

int Flag=0;
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

void mirrorBST(struct Node* root)
{
     if (root == NULL)  
        return;  
    else
    { 
        struct Node* temp; 
          
        /* recursively mirror the subtrees */
        mirrorBST(root->left); 
        mirrorBST(root->right); 
      
        /* swap the pointers in this node */
        temp     = root->left; 
        root->left = root->right; 
        root->right = temp; 
    } 
    
}

void traverseBST(struct Node* temp)
{
    if(temp)
    {
        traverseBST(temp->left);
        printf("%d ",temp->val);
        traverseBST(temp->right);
    }
}

int main(void) 
{
	int n;
    scanf("%d",&n);

    int arr[n];
    struct Node* root=NULL;
    	
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    	if(root==NULL)
    	    root=insert(root, arr[i]);
    	else 
    	    insert(root, arr[i]);
	}
	    
	mirrorBST(root);
	traverseBST(root);
	
	return 0;
}

