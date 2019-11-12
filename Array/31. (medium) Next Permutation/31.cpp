
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int cur =0;
        int i = nums.size()-1;
        for (int i = nums.size()-1; i > 0; i-- )
        {
            if(nums[i] > nums[i-1])
            {
                cur = i;
                int exchange = i;
                for (int j = i; j < nums.size(); j++)
                {
                    if(nums[j] > nums [i -1]) 
                        exchange = j;
                    else
                        break;
                }   
                std::swap(nums[exchange],nums[cur-1]);
                break;
            }
        }
        //if(cur == 0) std::sort(nums.begin(), nums.end());
        reverse(nums.begin()+cur,nums.end());
    }
};
