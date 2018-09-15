/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        int ans = 0;
        if(L.size() <= 0)
            return 0;
        long long r = LLONG_MIN;
        for(int i = 0; i < L.size(); ++ i){
            r = max((long long)L[i], r);
        }
        long long l = 1;
        while(l <= r){
            long long mid = (l + r)>>1;
            int cnt = Cal(mid, L);
            if(cnt >= k){
                ans = mid;
                l = mid + 1;
            }else
                r = mid - 1;
        }
        return ans;
    }
    
    int Cal(long long len, vector<int> L){
        int cnt = 0;
        for(int i = 0; i < L.size(); ++ i){
            cnt += L[i]/len;
        }
        return cnt;
    }
};
