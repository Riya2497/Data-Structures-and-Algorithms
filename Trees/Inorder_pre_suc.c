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

struct Node* nextValue(struct Node* n)
{
    struct Node* temp=n;
    while(temp->left)
    {
        temp=temp->left;
    }
    return temp;
}

struct Node* successor(struct Node* root,struct Node* n)
{
    if(!root)return NULL;
    
    if(n->right) return nextValue(n->right);
    struct Node* succ=NULL;
    while(root){
        if(root->val > n->val)
        {
            succ=root;
            root=root->left;
        }
        else if(root->val < n->val)
        {
            root=root->right;
        }
        else
            break;
    }
    
    return succ;
    
}

struct Node* maxValue(struct Node* root)
{
    struct Node* temp=root;
    while(temp->right)
    {
        temp=temp->right;
    }
    
    return temp;
}

struct Node* predecessor(struct Node* root, struct Node* key)
{
    if(!root)return NULL;
    
    if(key->left)return maxValue(key->left);
    
    struct Node* pred = NULL;
    
    while(root)
    {
        if(root->val > key->val)
        {
            root=root->left;
        }
        else if(root->val < key->val)
        {
            pred = root;
            root = root->right;
        }
        else break;
        
    }
    
    return pred;
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

struct Node* searchBST(struct Node* root,int n)
{
     if (root == NULL || root->val == n)
       return root;

    if (root->val < n)
       return searchBST(root->right, n);
 
    return searchBST(root->left, n);
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
	scanf("%d",&c);
	
	struct Node* temp=searchBST(root,c);
	struct Node* ans=successor(root,temp);
	struct Node* pred = predecessor(root,temp);
	ans ? printf("%d\n",ans->val) : printf("successor doesn't exist\n");
	pred ? printf("%d",pred->val) : printf("predecessor doesn't exist");
	
    return 0;
}
