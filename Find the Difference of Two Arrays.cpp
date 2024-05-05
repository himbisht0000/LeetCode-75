class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> mp1,mp2;
        map<int,int>::iterator it;
        vector<vector<int>> ans;
        vector<int> temp;

        int value;
        for(int i = 0; i < nums1.size() ; i++)
        {
            value = nums1[i];
            if(mp1.find(value) == mp1.end())
            {
                mp1[value] = 1;
            }
        }

        for(int i = 0; i < nums2.size() ; i++)
        {
            value = nums2[i];
            if(mp2.find(value) == mp2.end())
            {
                mp2[value] = 1;
            }
            
        }

       
        for( it = mp1.begin(); it!=mp1.end();it++)
        {
            if(mp2.find(it->first) == mp2.end())
            temp.push_back(it->first);
        }
        ans.push_back(temp);
        temp.clear();

        for( it = mp2.begin(); it!=mp2.end();it++)
        {
            if(mp1.find(it->first) == mp1.end())
            temp.push_back(it->first);
        }
        ans.push_back(temp);
        temp.clear();

        return ans;
    }
};
