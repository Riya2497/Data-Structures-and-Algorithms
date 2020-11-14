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

int isIdentical(TreeNode* root1, TreeNode* root2)
{
    if (root1 == NULL && root2 == NULL) 
        return 1; 
    else if (root1 != NULL && root2 == NULL) 
        return 0; 
    else if (root1 == NULL && root2 != NULL) 
        return 0; 
    else 
    {
        if (root1->val == root2->val && isIdentical(root1->left, root2->left) 
            && isIdentical(root1->right, root2->right)) 
            return 1; 
        else
            return 0; 
    } 
}

int main()
{
    int testcase;
    scanf("%d", &testcase);
    
    int n;
    scanf("%d", &n);
    int val;
    
    while(testcase--)
    {
        TreeNode* root1 = NULL;
        TreeNode* root2 = NULL;
    
        for(int i=0; i<2*n; i++)
        {
            scanf("%d", &val);
            if(i<n)
            root1 = insert(root1, val);
            else
            root2 = insert(root2, val);
        }
        
        if(isIdentical(root1, root2))
	    {printf("y\n");}
	    else
	    {printf("n\n");}
    }
    
    return 0;
}
