/*
* Algorithm: Binary Search
* Time complexity: O(logx)
* Memory complexity: O(1)
*/
class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 1, r = 46341;
        int mid = (l + r)>>1;
        if(x<=1) return x;
        while(l<=r)
        {
            mid = (l + r) >> 1;
            long long tmp = mid*mid;
            if(tmp == x) {r = mid;break;}
            else if(tmp < x) l = mid + 1;
            else r = mid - 1;
        }
        if((long long)r*r > x) r --;
        return r;
    }
};
