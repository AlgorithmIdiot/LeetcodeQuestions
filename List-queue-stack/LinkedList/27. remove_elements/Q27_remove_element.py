# -*- coding: utf-8 -*-

class Solution(object):
    def removeElement(nums, val):
        while val in nums:
            nums.remove(val)
        return nums
    
    
def main():
    s = Solution
    nums = [3,2,2,3]
    val = 3
    print(s.removeElement(nums,val))
    
    
if __name__ == '__main__':
    main()