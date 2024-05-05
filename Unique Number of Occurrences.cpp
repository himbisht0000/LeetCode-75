class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        map<int,int> freq;
        map<int,int>::iterator it;
        
        for(int i = 0 ;i<arr.size();i++)
        {
            if(mp.find(arr[i]) == mp.end())
            {
                mp[arr[i]] = 1;
            }
            else
            {
                mp[arr[i]]++;
            }
            
        }
    
        for(it = mp.begin(); it!=mp.end(); it++)
        {
            if(freq.find(it->second) == freq.end())
            freq[it->second] = 1;
            else
            return false;
        }

        return true;
    }
};
