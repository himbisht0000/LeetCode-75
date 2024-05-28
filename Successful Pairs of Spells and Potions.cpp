class Solution {
public:
    long long int experiment(int spell, vector<int>&potions, long long success)
    {
        long long left = 0, right = potions.size() - 1;
        unsigned long long mid , power;
        while(left < right)
        {
            mid = left + (right - left )/2;
            power = (long long)(potions[mid]) * (long long)(spell);
            if(power >= success)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        power = (long long)(potions[left]) * (long long)(spell);
        if(power < success)
        {
            left++;
        }

        return potions.size() - left;

    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> count;
        //sort potions
        sort(potions.begin(),potions.end());

        for(int i = 0; i < spells.size(); i++)
        {
            count.push_back(experiment(spells[i],potions,success));
        }

        return count;
    }
};
