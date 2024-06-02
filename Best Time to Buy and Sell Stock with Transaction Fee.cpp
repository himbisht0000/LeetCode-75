class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int profit[prices.size()][2];
        memset(profit,0,sizeof(int) * prices.size() * 2);
        
        //profit will be zero when we do not have any stock
        profit[0][0] = 0 ; 

        // this is the first stock we buy
        profit[0][1] = -1 * prices[0];
        
        for(int i = 1; i < prices.size() ; i++)
        {
            for(int j= 0; j < 2; j++)
            {
                //selling the stock
                if( j == 0)
                {
                    // if we want to sell the stock thn
                    // 1 . sell the stock and add cost incurrerd when we bought it on previous day
                    // 2 . We do not do any thing , here we will simply take value from sell when we bought stock last time
                    profit[i][j] = max( profit[i-1][1] + prices[i] - fee , profit[i-1][0]);
                }
                else
                {
                    profit[i][j] = max( profit[i-1][0] - prices[i] , profit[i-1][1]);
                }
            }
        }

        // at the end of last day we should sell the stock 
        return profit[prices.size()-1][0];

    }
};
