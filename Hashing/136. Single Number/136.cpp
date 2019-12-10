class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (auto & i : nums)
        {
            if (!mp[i]) 
                mp[i]++;
            else
                mp[i]--;
        }
        for (auto & i: nums){
            if (mp[i]) return i ;}
        return -1;
    }
};