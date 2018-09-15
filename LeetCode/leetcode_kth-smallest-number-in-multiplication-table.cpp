/*
*
* Tag: Binary Search
* Time: O(min(m,n)log(mn))
* Space: O(1)
*/
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        if(m*n <= 0 || k <= 0){
            return -1;
        }
        
        if(m > n){
            swap(m, n);
        }
        
        int l = 1, r = m*n;
        while(l < r){
            int mid = (l + r)>>1;
            int cnt = 0;
            for(int i = 1; i <= m; ++ i) {
                int delta = min(mid/i, n);
                cnt += delta;
            }
            if(cnt < k){
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        return l;
    }
};
