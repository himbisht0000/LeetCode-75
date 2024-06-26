class Solution {
public:
    int maxArea(vector<int>& height) {
        // initialise left and right pointer
        int left = 0,right = height.size() - 1;
        // stores the maximum area found till now
        int area = 0;

        while(left < right)
        {
            area = max(area , min(height[left] , height[right]) * (right - left));

            // compare the height of left and right pointer
            // we know area is limited by the smallest height out of two pointer
            // so pointer at smaller height will be moved towards center
            if( height[left] > height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        //we are only traversing the height array
        //TC : O(n)
        return area;

    }
};
