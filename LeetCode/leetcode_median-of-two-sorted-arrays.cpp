/*
*
* Tag: Binary Search
* Time: O(lg(n + m))
* Space: O(1)
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int left = 0, right = n;
        while(left <= right){
            int i = (left + right)>>1;
            int j = (n + m + 1)/2 - i;
            
            int l1 = i > 0 ? nums1[i - 1] : INT_MIN;
            int r1 = i < n ? nums1[i] : INT_MAX;
            int l2 = j > 0 ? nums2[j - 1] : INT_MIN;
            int r2 = j < m ? nums2[j] : INT_MAX;
            
            if(l1 > r2) {
                right = i - 1;
            } else if(r1 < l2) {
                left = i + 1;
            } else {
                return (n + m)%2 == 0 ? (double)(max(l1, l2) + min(r1, r2))/2.0 : max(l1, l2);
            }
        }
        return 0;
    }
};

