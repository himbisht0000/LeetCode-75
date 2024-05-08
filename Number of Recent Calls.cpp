class RecentCounter {
public:
    queue<int> q;
    int left = -3000 ,right = 0;
    RecentCounter() {
        while(!q.empty())
        {
            q.pop();
        }
    }
    
    int ping(int t) {
        left = -3000;
        q.push(t);
        left+=t;
        right = t;

        while( q.front() < left )
        {
            q.pop();
            if(q.empty())
            break;
        }

        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
