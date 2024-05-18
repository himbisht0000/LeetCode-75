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
    vector<int> leaf_node_1;
    vector<int> leaf_node_2;

    void dfs(TreeNode* root, int type)
    {
        if(root == NULL)
        {
            return;
        }

        if(root->left == NULL && root->right == NULL)
        {
            if(type == 0)
            leaf_node_1.push_back(root->val);
            else
            leaf_node_2.push_back(root->val);

            return;
        }

        dfs(root->left , type);
        dfs(root->right, type);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        dfs(root1 , 0);
        dfs(root2 , 1);

        if(leaf_node_1.size() != leaf_node_2.size())
        {
            return false;
        }
        for(int i = 0; i < leaf_node_1.size() ; i++)
        {
            if(leaf_node_1[i] != leaf_node_2[i])
            {
                return false;
            }
        }

        return true;
    }
};
