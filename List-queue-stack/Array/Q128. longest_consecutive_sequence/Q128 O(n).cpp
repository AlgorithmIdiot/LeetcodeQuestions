class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_map<int, int> m ; 
        int max = 0; 
        for (int i = 0; i < nums.size(); i ++ ) m[nums[i]]++;
        for (int i = 0; i < nums.size(); i ++){
            int cur = nums[i];
            int len =1; 
            while (m[cur+1]){
                len++;
                cur++;
            }
            if (len>max) max = len;
        }
        return max;
    }
};