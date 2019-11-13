class Solution:
    def threeSumClosest(nums, target):
        nums.sort()
        for i in range(0,len(nums)-1):
            last = len(nums)-1
            j = i + 1
            results = nums[i]+nums[j]+nums[last]
            d = abs(results-target)
            if i>0 and nums[i] == nums[i-1]:
                continue
            while j<last:
                if abs(nums[i]+nums[j]+nums[last]-target) < d:
                    j+=1
                    while nums[j]==nums[j-1] and j<last:
                        j+=1
                    results = nums[i]+nums[j]+nums[last]
                elif abs(nums[i]+nums[j]+nums[last]-target) > d:
                    last-=1
                    while nums[last+1]==nums[last] and last>j:
                        last-=1
                else:
                    j+=1
                    last-=1
                    while nums[j]==nums[j-1] and nums[last]==nums[last+1] and j<last:
                        j+=1
        return results

def main():
    s=Solution
    a = [-1, 2, 1, 4]
    print(s.threeSumClosest(a,1))
    
if __name__ == '__main__':
    main()
        
        