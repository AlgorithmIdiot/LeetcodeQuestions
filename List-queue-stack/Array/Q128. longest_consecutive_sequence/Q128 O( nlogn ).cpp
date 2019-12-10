// this exceed the time limit 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int maxCon = 0;
        int i = 0 , j = i + 1;
        while (j < nums.size())
        {
            if (nums[j]-nums[j-1]> 1)
            {
                maxCon = std::max((j - i + 1 ), maxCon);
                i = j ;
                j ++;
            }
        }
        return maxCon;
    }
};