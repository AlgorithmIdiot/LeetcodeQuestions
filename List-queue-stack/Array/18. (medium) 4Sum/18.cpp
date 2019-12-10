class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n< 4) return {};
        for (int i = 0 ; i < nums.size()-3; ++i )
        {
           
            if (nums[i] + nums[n-1] + nums[n-2] +nums[n-3] < target) continue;
             if  (nums[i] + nums[i+1] + nums[i+2] +nums[i+3] > target) break;
            for (int j = i + 1; j < nums.size() -2; ++ j )
            {
                
                if (nums[i]+ nums[j] +nums[j+1] + nums[j+2] > target) break;
                if(nums[i]+ nums[j] +nums[n-1] + nums[n-2] < target) continue;
                int left = j +1, right = nums.size() -1;
                int newtarget = target - nums[i]- nums[j];
                while (left < right )
                {
                    int sum = nums[left] + nums[right];
                    if (sum < newtarget)
                        left ++ ;
                    else if (sum > newtarget)
                        right -- ;
                    else 
                    {
                        res.push_back({nums[i], nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[left] == res.back()[2]) left++;
                        while(left < right && nums[right] == res.back()[3]) right--;
                    }
           
                }
                while(j+1 < nums.size() && nums[j] == nums[j+1]) j++;
            }
            while (i+1<nums.size() && nums[i] == nums[i+1]) i ++;
        }
        return res;
    }
};