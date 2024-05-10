/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL)
        return root;
        TreeNode *left,*right;
        left = right = NULL;
        
        left = lowestCommonAncestor(root->left,p,q);
        right = lowestCommonAncestor(root->right,p,q);

        if(left != NULL && right != NULL)
        {
            return root;
        }
        else if( left != NULL)
        {   
            if(root->val == p->val || root->val == q->val)
            return root;
            else
            return left;
        }
        else if(right != NULL)
        {
            if(root->val == p->val || root->val == q->val )
            return root;
            else
            return right;
        }
        else if(root->val == p->val || root->val == q->val)
        {
            return root;
        }
        
        return NULL;
        



    }
};
