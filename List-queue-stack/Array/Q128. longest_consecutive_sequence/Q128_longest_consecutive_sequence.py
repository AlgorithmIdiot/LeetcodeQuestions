class Solution:
    def longestconsecutive(self,nums):
        nums.sort()
        l = 0
        for i in range(0,nums.length()):
            m = 0
            if nums[i]==nums[i+1]-1:
                m = m + 1
            else:
                
            