/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
/ * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge wether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int l = 1, r = n, ans = n;
        if(n == 1)
            return ans;
        VersionControl vc;
        while(l <= r){
            int mid = (l + r)>>1;
            if(vc.isBadVersion(mid)){
                ans = mid;
                r = mid - 1;
            }else
                l = mid + 1;
        }
        while(ans > 1 && vc.isBadVersion(ans - 1) ) -- ans;
        return ans;
    }
};

