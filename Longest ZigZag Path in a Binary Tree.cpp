
class Solution {
public:
    // store the maximum zigzag path
    int output = 0;
    void solve(TreeNode* root , char dir, int path)
    {
        // base condition if node is null simply return
        if(root == NULL)
        return ;
        
        //store max path we have found till now
        output = max(output,path);
       
        //check if we have to go left or right
        if(dir == 'L')
        {
            // if we go to left and increasing length of zigzag path
            solve(root->left,'R', path + 1);
            // if we go to right we simply pass 1 as zigzag path will restart
            solve(root->right,'L', 1);
        }
        else
        {
            // if we go to left we simply pass 1 as zigzag path will restart
            solve(root->left,'R', 1);
            // if we go to right and increasing length of zigzag path
            solve(root->right,'L', path + 1);
        }

        return ;
    }
    int longestZigZag(TreeNode* root) {
        
        if(root == NULL)
        return 0;     

        // find longest zigzag path by going firts left then right
        solve(root , 'L' , 0);
        solve(root, 'R' , 0);

        return output;
    }
};
