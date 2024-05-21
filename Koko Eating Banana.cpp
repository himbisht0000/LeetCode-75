class Solution {
public:
    long long cal_hour(vector<int> piles, int hour)
    {
        long long ans = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            ans += piles[i]/hour;
            
            if(piles[i] % hour)
            {
                ans++;
            }
        }

        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int mini = 1, maxi = piles[0];
        long long left, right, mid, hours;
        int ans;
        for(int i = 0; i < piles.size() ;i++)
        {
            maxi = max(piles[i], maxi);
        }   

        left  = mini;
        right  = maxi;

        while(left < right)
        {
            mid = (left + right)/2;
            
            hours = cal_hour(piles,mid);
            cout<<"left = "<<left<<" right = "<<right<<" mid -> "<<mid<<" hours "<<hours<<endl;
            if(hours <= h)
            {
                ans = mid;
            }
            if(hours <= h)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
            
        }

        cout<<"final left = "<<left<<" right = "<<right<<" mid -> "<<mid<<" hours "<<cal_hour(piles,left)<<endl;
        if(left == right  && ( cal_hour(piles,left) <= h ))
        return left;

        return ans;
    }
};
