class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> first,second;
        int marker_1 , marker_2 = costs.size() - 1;
        long long total_cost = 0;
        int first_can = -1 , second_can = -1;
        for(int i = 0; i < candidates ; i++)
        {
            first.push(costs[i]);
        }
        marker_1 = candidates - 1;

        for(int i = 0 ; i < candidates ; i++)
        {
            if(marker_2 <= marker_1)
            {
                break;
            }
            second.push(costs[marker_2]);
            if(marker_2 - marker_1 == 1 || (i + 1 ) == candidates)
            break;
            marker_2--;
        }

        cout<<"marker 2 --> "<<marker_1<<" marker 2-->"<<marker_2<<endl;
        while(k--)
        {
            if(!first.empty())
            first_can = first.top();

            if(!second.empty())
            second_can = second.top();

            cout<<"first -> "<<first_can<<" second -> "<<second_can<<endl;
            if(( second_can == -1 && first_can != -1) || (first_can != -1 && first_can <= second_can ) )
            {
                total_cost += first_can;
                first_can = -1;
                first.pop();
                if( (marker_2 - marker_1) > 1)
                {
                    marker_1++;
                    first.push(costs[marker_1]);
                    
                }
            }
            else if( second_can != -1)
            {
                total_cost += second_can;
                second_can = -1;
                second.pop();
                if( (marker_2 - marker_1) > 1)
                {
                    marker_2--;
                    second.push(costs[marker_2]);
                }
                
            }

        }


        return total_cost;


    }
};
