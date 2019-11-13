# -*- coding: utf-8 -*-

# idea: we can consider the list as a decimal number, the question simply becomes:
    # given a decimal number, find a next larger number. you swap the digits where
    # *left > *right, then the following numbers should be in ascending sequence.
    

class Solution(object):
    def nextPermutation(nums):
        if len(nums)<=1:
            pass
        else:
            for i in range(len(nums)-1, 0,-1):
                if nums[i]>nums[i-1]:
                    break
            if i-1==0 and nums[i]<=nums[i-1]:
                nums.reverse()
            else:
                print('i=',i)
                k = nums[i:].index(min(x for x in nums[i:] if x >= nums[i-1])) 
                print('k=',k)
                #k = nums.index(min(nums[i:]))
                print(nums[i-1],k)
                nums[i-1], nums[k] = nums[k], nums[i-1]
                nums[i:] = sorted(nums[i:])

        
        
def main():
    nums = [1,2,3]

    s = Solution
    s.nextPermutation(nums)
    print(nums)
    
    
if __name__ == '__main__':
    main()