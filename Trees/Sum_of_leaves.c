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

int sum_of_leaves(TreeNode* node)
{
    if(!node)
    return 0;
    
    if (!node->left && !node->right) 
         return node->data; 
         
    return sum_of_leaves(node->left) + sum_of_leaves(node->right);

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
	
	int sum = 0;
	
	printf("%d", sum_of_leaves(root));
	
	return 0;
}