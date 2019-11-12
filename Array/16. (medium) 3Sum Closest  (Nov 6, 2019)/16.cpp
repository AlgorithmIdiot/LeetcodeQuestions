class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=0;
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        if (nums.size() == 3 ) return nums[0]+nums[1]+nums[2];
        
        for (int i = 0; i < nums.size()-2; ++i)
        {
            int left = i + 1;
            int right= nums.size()-1;
            while (left < right)
            {
            int sum = nums[i] + nums[left] +nums[right];
            if (sum == target) return target;
            else if (  sum > target)  
            {   
                right --;
            }
            else left ++;
            if (abs(sum -target) < diff) {
                diff = abs(sum -target);
                res = sum;
            }}
        }
        return res;    
    }
