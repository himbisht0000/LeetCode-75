class Solution {
public:
    static bool compare(const pair<int,int>& a, const pair<int,int>& b)
    {
        return a.first > b.first;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // min heap
        priority_queue<int , vector<int>, greater<int>> q;
        vector<pair<int,int>> data;
        long long sum = 0;
        long long ans = 0;
        int mini = 0;
        for(int i = 0; i < nums2.size(); i++)
        {
            data.push_back({nums2[i],nums1[i]});
        }
        // sort the data based on nums2 in descending order
        sort(data.begin(), data.end() , compare);

        for( int i = 0; i < k ;i++)
        {
            sum += data[i].second;
            mini = data[i].first;
            q.push(data[i].second);
        }
        ans = sum * mini;
        for( int i = k; i < data.size() ;i++)
        {
            mini = data[i].first;
            sum = sum - q.top() + data[i].second;
            q.pop();
            q.push(data[i].second);
            ans = max(ans, sum * mini);
        }
        return ans;
    }
};
