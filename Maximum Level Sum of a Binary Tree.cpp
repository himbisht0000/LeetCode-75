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
    void solve(TreeNode *root, int level, vector<int>&ans)
    {
        if(NULL == root)
        return ;

        if(ans.size() == level)
        {
            ans.push_back(root->val);
        }
        else{
            ans[level] += root->val;
        }
        solve(root->left, level + 1 , ans);
        solve(root->right, level + 1, ans);
    }
    int maxLevelSum(TreeNode* root) {
        vector<int> ans;
        int max_index = -1;
        int max_value;
        solve(root, 0, ans);
        if(ans.size() > 0 )
        {
            max_value = ans[0]; 
            max_index = 0;
        }
        // find the  index with max value
        for(int i = 1;i<ans.size();i++)
        {
            if(max_value < ans[i])
            {
                max_value = ans[i];
                max_index = i;
            }
        }
    
    return max_index + 1;
    }
};
