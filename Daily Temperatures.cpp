class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size());
        int next_index = 0;
        int next_value = 0;
        fill(ans.begin(),ans.end(),0);
        for(int i = 0; i < temperatures.size(); i++)
        {
            next_index = i + 1;
            if(next_index == temperatures.size())
            {
                continue;
            }

            if(temperatures[next_index] <= temperatures[i])
            {
                st.push(i);
            }
            else
            {
                ans[i] = next_index - i;
                next_value = temperatures[next_index];
                
                while(!st.empty())
                {
                    if(next_value > temperatures[st.top()] )
                    {
                        ans[st.top()] = next_index - st.top();
                        st.pop();
                    }
                    else    
                    {
                        break;
                    }
                }
            }

        }

        return ans;
    }
};
