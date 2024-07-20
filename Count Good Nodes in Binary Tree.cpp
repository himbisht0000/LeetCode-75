/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve (TreeNode* root , int *count, int max)
    {   
        //BAse condition
        if(root == NULL)
        return ;
        // if val of current node is more than max in its path then count it
        if(root->val >= max)
        {
            *count = *count + 1 ;
            max = root->val;
        }
        solve(root->left, count,max);
        solve(root->right,count, max);
        
    }
    int goodNodes(TreeNode* root) {
        int count  = 0;
        int max = root->val;
        solve(root,&count,max);
        //TC : O(N) where N is the number of node in binary tree
        return count ;
    }
};
