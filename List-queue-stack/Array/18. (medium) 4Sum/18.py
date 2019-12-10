
class Solution:
    def fourSum(self, nums, target):
        results = []
        nums.sort()
        for i in range(0, len(nums)-2):
            if i>0 and nums[i]==nums[i-1]:
                continue
            for j in range(i+1,len(nums)-1):                
                left = j + 1
                right = len(nums)-1
                if j>i+1 and nums[j]==nums[j-1]:
                    continue
                while left < right:
                    curr_sum = nums[i] + nums[j] + nums[left] + nums[right]
                    if curr_sum > target:
                        right -= 1
                        while nums[right] == nums[right+1] and left<right:
                            right -= 1                       
                    elif curr_sum < target:
                        left += 1
                        while nums[left] == nums[left-1] and left<right:
                            left += 1
                    else:
                        results.append([nums[i],nums[j],nums[left],nums[right]])
                        left += 1
                        right -= 1
                        while nums[left]==nums[left-1] and nums[right]==nums[right+1] and left<right:
                            left += 1
        return results
