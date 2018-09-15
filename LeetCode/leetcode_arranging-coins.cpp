/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0;
        if(!n)
            return ans;
        ans = getRows(n);
        return ans;
    }
private:
    int getRows(int target){
        long long l = 1, r = target, mid = 0, v = 0, ans = 0;
        while(l <= r){
            mid = l + ((r - l)>>1);
            v = (mid*(mid + 1))>>1;
            if(v <= target){
                ans = max(ans, mid);
                l = mid + 1;
            }else
                r = mid - 1;
        }
        return (int)ans;
    }
};
