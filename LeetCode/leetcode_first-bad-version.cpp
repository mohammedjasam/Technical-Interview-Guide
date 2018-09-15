/*
*
* Tag: Binary Search
* Time: O(logn)
* Space: O(1)
*
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int ans = n;
        if(n < 2)
            return n;
        long long l = 1, r = n;
        while(l <= r){
            long long mid = (l + r)>>1;
            if(isBadVersion(mid)){
                ans = (int)mid;
                r = mid - 1;
            }else
                l = mid + 1;
        }
        return ans;
    }
};
