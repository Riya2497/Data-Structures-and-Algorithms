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
    if(!temp) return createNode(newNode);
    
    if(temp->val > newNode)
        temp->left = insert(temp->left,newNode);
    else 
        temp->right = insert(temp->right,newNode);
        
    return temp;
}


void BFS(struct Node* root,int n)
{
    struct Node* queue[n+1];
    int i=0;
    queue[i++]=root;
    int j=1,c=0;
    while(i<n+1){
        int size=0;
        while(c<j)
        {
            printf("%d ",queue[c]->val);
            
            if(queue[c]->left)
            {
                queue[i++]=queue[c]->left;
                size++;
            }
            
            if(queue[c]->right)
            {
                queue[i++]=queue[c]->right;
                size++;
            }
            else if(!queue[c]->left && !queue[c]->right && i==n)
            {
                i++;
            }
            c++;
        }
        j=size+c;
    }
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

	BFS(root,n);
	
    return 0;
}
