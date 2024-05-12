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
    TreeNode* find_MIN(TreeNode* root)
    {
        if(root->left == NULL)
        return root;

        return find_MIN(root->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL)
        return root;

        if(key < root->val)
        {
            root->left = deleteNode(root->left , key);
        }
        else if( key > root->val)
        {
            root->right = deleteNode(root->right , key);
        }
        else
        {
            //if leaf node
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            else if(root->right == NULL)
            {
                TreeNode* temp;
                temp = root;
                root = root->left;
                delete temp;
            }
            else if(root->left == NULL)
            {
                TreeNode* temp;
                temp = root;
                root = root->right;
                delete temp;
            }
            else
            {
                TreeNode* temp;
                temp = find_MIN(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right , temp->val);
            }
        }

        return root;
    }
};
