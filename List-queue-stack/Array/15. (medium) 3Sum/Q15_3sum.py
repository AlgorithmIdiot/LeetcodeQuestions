

class Solution:
    def threeSum(nums):
        results=[]
        nums.sort()
        for i in range(0,len(nums)):
            last = len(nums)-1
            j = i + 1
            if i>0 and nums[i] == nums[i-1]:
                continue
            while j<last:
                if nums[i]+nums[j]+nums[last] < 0:
                    j+=1
                    while nums[j]==nums[j-1] and j<last:
                        j+=1
                elif nums[i]+nums[j]+nums[last] > 0:
                    last-=1
                    while nums[last+1]==nums[last] and last>j:
                        last-=1
                else:
                    results.append([nums[i],nums[j],nums[last]])
                    j+=1
                    last-=1
                    while nums[j]==nums[j-1] and nums[last]==nums[last+1] and j<last:
                        j+=1
        return results

def main():
    s=Solution
    a = [-1, 0, 1, 2, -1, -4]
    print(s.threeSum(a))
    
if __name__ == '__main__':
    main()
                    
        
    