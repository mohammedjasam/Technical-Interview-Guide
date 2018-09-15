/*
*
* Tag: Math
* Time: O(lgx)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        int ans = x;
        if(x < 2)
            return ans;
        int l = 2, r = x;
        while(l <= r){
            int mid = (l + r)>>1;
            if(x/mid  == mid){
                ans = mid;
                break;
            }else if(x/mid < mid){
                r = mid - 1;
            }else{
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }
};
