
/*IDEA 1
Combine the two sorted arrays 
Decide weather the combined array is even or odd
Return the value 
*/ 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // combine the two arrays
        int i =0, j = 0;
        vector<int> combine;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j]) {
                combine.push_back(nums1[i]);
                i++;
            }
            else
            {
                combine.push_back(nums2[j]);
                j++;
            }
        }
        while (i == nums1.size() && j < nums2.size()) 
        {
            combine.push_back(nums2[j]);
            j++;
        }
        while (j == nums2.size() && i < nums1.size())
        {
            combine.push_back(nums1[i]);
            i++;
        }
        if (combine.size() % 2 != 0) 
            return combine[ combine.size()/2 ];
        else 
            return (combine[combine.size()/2.0 ] + combine[combine.size()/2-1] )/2.0;
        
    }
};
