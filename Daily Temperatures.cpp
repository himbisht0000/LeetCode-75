class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //stack to store the decreasing temperature index
        stack<int> st;
        vector<int> output(temperatures.size());
        int next_index = 0;
        int next_value = 0;
        // reset 
        fill(output.begin(),output.end(),0);
        for(int i = 0; i < temperatures.size(); i++)
        {
            //store index of next element
            next_index = i + 1;

            // break out of loop we are at last index
            if(next_index == temperatures.size())
            {
                break;
            }

            // if current temperature is greater than equals to the next temperature
            // store it in index
            if(temperatures[i] >= temperatures[next_index] )
            {
                st.push(i);
            }
            else
            {
                // next temperatur is more than current temperature them at i we should store 1 
                // as after onde day we will see more temperature
                output[i] = 1;

                // store this next day temperature
                next_value = temperatures[next_index];
                
                // try to check in stack if this next day temperature is more than temperature on days stored in stack 
                while(!st.empty())
                {
                    
                    if(next_value > temperatures[st.top()] )
                    {
                        output[st.top()] = next_index - st.top();
                        st.pop();
                    }
                    else    
                    {   /* if next day temperature is not more than the top index temperature then it will */
                        /* not be more than any other tempearture in */
                        break;
                    }
                }
            }

        }

        // TC : O(N) , N is the size of the temperatures array
        return output;
    }
};
