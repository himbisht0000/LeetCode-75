class Solution {
public:
    void solve(TreeNode* root, long long &ans , long long current_sum, map<long long,long long>& target, int targetSum)
    {
        //Base condition
        if(root == NULL)
        return;

        //update the current sum 
        current_sum  += (long long)root->val;

        //Check if prefix sum exists in map or not
        if(target.find(current_sum - targetSum) != target.end() )
        {
            ans += target[current_sum - targetSum];
        }

        // Update the entry of new sum in map
        if(target.find(current_sum) == target.end())
        {
            cout<<"current_sum"<<current_sum<<endl;
            target[current_sum] = 1;
        }
        else
        {
            target[current_sum]++;
        }
        
        // traversing the tree 
        solve(root->left,ans,current_sum,target,targetSum);
        solve(root->right,ans,current_sum,target,targetSum);
        
        // reduce the count of frequency
        target[current_sum]--;

    }
    int pathSum(TreeNode* root, int targetSum) {
        map<long long,long long> target;
        long long ans = 0;
        // if current sum exactly matches the targetSum then in map thier should be a entry of zero
        target[0] = 1;
        solve(root,ans,0,target,targetSum);

        return ans;
    }
};
