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


void findPath(struct Node* root,int path[],int len)
{
    if(root==NULL)return;
    
    path[len++]=root->val;
    
    if(!root->left && !root->right)
    {
        for(int i=0;i<len;i++){
            printf("%d ",path[i]);
        }
        printf("\n");
    }
    
    else{
        findPath(root->left,path,len);
        findPath(root->right,path,len);
    }
}

void rootToLeaf(struct Node* root)
{
    int path[100];
    findPath(root,path,0);
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
	    if(root==NULL)root=insert(root, arr[i]);
	    else insert(root, arr[i]);
	}
	
	rootToLeaf(root);
    return 0;
}
