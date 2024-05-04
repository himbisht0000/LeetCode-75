class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int direction;
        int value;

        for(int i = 0; i < asteroids.size(); i++)
        {
            if(ans.size() == 0)
            {
                ans.push_back(asteroids[i]);
            }
            else
            {
                if(asteroids[i] < 0)
                {
                    direction = -1;
                    value = abs(asteroids[i]);
                }
                else
                {
                    direction = 1;
                    value = abs(asteroids[i]);
                }
                //number is negative
                if(direction == -1)
                {
                    if(ans[ans.size() - 1] < 0 )
                    {
                        ans.push_back(value * -1);
                        cout<<value * -1<<endl;
                    }
                    else
                    {
                        if(ans[ans.size() - 1] == value)
                        {
                            ans.pop_back();
                            continue;
                        }
                        while(ans.size() > 0  )
                        {
                            if(ans[ans.size() -1] == value)
                            {
                                ans.pop_back();
                                break;
                            }
                            ans[ans.size() - 1] = max(ans[ans.size() -1],value);
                            if(ans[ans.size() - 1] == value)
                            {
                                ans.pop_back();
                                //ans[ans.size() - 1] = ans[ans.size() - 1] * -1;
                            }
                            else
                            {
                              break;
                            }

                            if( ans.size() == 0 || ans[ans.size() - 1] < 0 )
                            {
                                ans.push_back(value * -1);
                                break;
                            }
                        }
                    }
                }
                else
                {
                    ans.push_back(value);  
                }
            }
        }

        return ans;
    }
};
