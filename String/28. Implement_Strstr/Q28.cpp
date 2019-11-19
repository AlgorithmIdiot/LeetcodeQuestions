class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() ==0 ) return 0;
        int hay =0;
        while( hay< haystack.length() &&  needle.size() <= (haystack.size() - hay))
        {
            if(haystack[hay] == needle[0])
            {
                int i = 0;
                for (;i< needle.size(); i++)
                {
                    if (haystack[hay+i] != needle[i]) break;
                }
                if (i == needle.size()) return hay;
            }
            hay++;
        }
        return -1;
    }
};