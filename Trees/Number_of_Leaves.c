#include <stdio.h>
#include <malloc.h>

struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
};

typedef struct TreeNode TreeNode;

TreeNode* insert(TreeNode* root, int val)
{
    if(!root)
    {
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        node->data = val;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    
    if(val<=root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    
    return root;
}

unsigned int getLeafCount(TreeNode* node)
{
    if(node==NULL)
    return 0;
    if(node->left==NULL && node->right==NULL)
    return 1;
    
    else
    return getLeafCount(node->left) + getLeafCount(node->right);
}

int main() 
{
	int n;
	scanf("%d", &n);
	
	TreeNode* root = NULL;
	int val;
	
	for(int i=0; i<n; i++)
	{
	    scanf("%d", &val);
	    root = insert(root, val);
	}
	
	printf("%d", getLeafCount(root)); 
	
	return 0;
}