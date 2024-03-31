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
    int answer = 0;
    void solve(TreeNode* root , char dir, int path)
    {
        if(root == NULL)
        return ;
        
        answer = max(answer,path);
        if(dir == 'L')
        {
            solve(root->left,'R', path + 1);
            solve(root->right,'L', 1);
        }
        else
        {
            solve(root->left,'R', 1);
            solve(root->right,'L', path + 1);
        }

        return ;
    }
    int longestZigZag(TreeNode* root) {
        
        if(root == NULL)
        return 0;     

        solve(root , 'L' , 0);
        solve(root, 'R' , 0);

        return answer;
    }
};
