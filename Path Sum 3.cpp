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
    void solve(TreeNode* root, long long &ans , long long current_sum, map<long long,long long>& target, int targetSum)
    {
        if(root == NULL)
        return;

        current_sum  = (long long)current_sum + (long long)root->val;

        if(target.find(current_sum - targetSum) != target.end() )
        {
            ans += target[current_sum - targetSum];
        }

        if(target.find(current_sum) == target.end())
        {
            cout<<"current_sum"<<current_sum<<endl;
            target[current_sum] = 1;
        }
        else
        {
            target[current_sum]++;
        }

        solve(root->left,ans,current_sum,target,targetSum);
        solve(root->right,ans,current_sum,target,targetSum);
        
        // reduce the count of frequency
        if(target[current_sum] >= 1)
        target[current_sum]--;

    }
    int pathSum(TreeNode* root, int targetSum) {
        map<long long,long long> target;
        long long ans = 0;
        // if current sum exactly matches the targetSum then in map thier should be a wntry of zero
        target[0] = 1;
        solve(root,ans,0,target,targetSum);

        return ans;
    }
};
