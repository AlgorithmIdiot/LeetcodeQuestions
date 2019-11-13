
## leetcode Q28

class Solution:
    def strStr(haystack, needle):
        a = haystack.find(needle)
        print(a)
        return a
    
def main():
    haystack = "hello"
    needle = "ll"
    aa = Solution
    aa.strStr(haystack,needle)
    
if __name__ == '__main__':
    main()