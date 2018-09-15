/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        vector<int> ans;
        if(!nums1.size() || !nums2.size())
            return ans;
        ans.resize(nums1.size() + nums2.size());
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int>::iterator it = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), ans.begin());
        ans.resize(it - ans.begin());
        return ans;
    }
};
