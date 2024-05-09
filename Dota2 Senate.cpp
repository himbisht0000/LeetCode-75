class Solution {
public:
    int find_opp(deque<char>&q , char opp)
    {
        stack<char> st;
        int result = 0;
        while( !q.empty() )
        {
            if(q.front() == opp)
            {
                st.push(opp);
                q.pop_front();
            }
            else
            {
                result = 1;
                q.pop_front();
                while(!st.empty())
                {
                    q.push_front(st.top());
                    st.pop();
                }
                break;
            }
        }

        return result ;
    }

    string predictPartyVictory(string senate) {
        deque<char> q;
        string winner;
        char current_senate;
        int result;
        for(int i = 0; i < senate.length() ; i++)
        {
            q.push_back(senate[i]);
        }
        
        while(!q.empty())
        {
            current_senate = q.front();
            q.pop_front();
            if(current_senate == 'R' )
            {
                result = find_opp(q , 'R');
                q.push_back('R');
                cout<<" R result"<<result<<endl;
                if(result == 0)
                {
                    winner = "Radiant";
                    break;
                }
            }
            else
            {    
                result = find_opp(q, 'D');
                cout<<" D result"<<result<<endl;
                q.push_back('D');
                if(result == 0)
                {
                    winner = "Dire";
                    break;
                }
            }
        }

        return winner;

    }
};
