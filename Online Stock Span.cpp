class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int span = 0;
        // remove the elements from stack till they are <= current price
        // and keep on adding their span 
        while(!st.empty() && st.top().first<= price)
        {
            span += st.top().second;
            st.pop();
        }
        // add one more span for including current day
        span++;

        st.push({price,span});

        //TC : O(N)
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
