class Solution {
public:
    void solve(int k , int n, int sum, vector<int> pattern, vector<int>& numbers, vector<vector<int>>& answer, int idx)
    {
        if(k==0)
        {   
            cout<<"sum = "<<sum<<"*";
            for(int i = 0 ; i < pattern.size(); i++)
            {
                cout<<pattern[i]<<" ";
            }
            cout<<endl;
            if(sum == n)
            {
                cout<<"pus"<<endl;
                answer.push_back(pattern);
            }
            else
            {
                return;
            }
        }

        if(sum > n)
        return;

        for(int i = idx; i <= 9 ;i++)
        {
            
                pattern.push_back(i);
                solve( k-1 , n , sum + i , pattern ,numbers,answer, i + 1);
                pattern.pop_back();

           
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> number(10);
        vector<int> pattern;
        vector<vector<int>> answer;

        fill(number.begin(), number.end(),0);
        solve( k , n , 0 , pattern , number, answer, 1 );
        
        return answer;

    }
};
