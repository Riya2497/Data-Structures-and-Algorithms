#include <stdio.h>
#include <malloc.h>

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
};

typedef struct TreeNode TreeNode;

TreeNode* insert(TreeNode* root, int val)
{
    if(!root)
    {
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    
    if(val<=root->val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    
    return root;
}

int search(TreeNode* root, int val)
{
    if(!root)
    return 0;
    if(root->val == val)
    return 1;
    
    if(val<=root->val)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
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
	
	int k, search_val;
	scanf("%d", &k);
	
	for(int i=0; i<k; i++)
	{
	    scanf("%d", &search_val);
	    if(search(root, search_val))
	    {printf("y\n");}
	    else
	    {printf("n\n");}
	}
	
	return 0;
}