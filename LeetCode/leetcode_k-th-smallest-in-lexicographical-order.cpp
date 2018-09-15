/*
*
* Tag: Math
* Time: O(10^3)
* Space: O(1)
*/
class Solution {
public:
    int findKthNumber(int n, int k, int start = 0) {
        if(k > 0){
            int cnt = 0;
            for(int i = (start == 0)?1:0; i <= 9; ++ i){
                cnt = numbersBeginWith(n, 10*start+i);
                if(k <= cnt)
                    return findKthNumber(n, k - 1, 10*start + i);
                k -= cnt;
            }
        }
        return start;
    }
    
private:
    int numbersBeginWith(int n, int prefix){
        int cnt = 0;
        long long minval = 0, maxval = 0, fac = 1;
        for(int i = 1; i <= 9; ++ i){
            minval = prefix*fac, maxval = prefix*fac + fac - 1;
            if(n < minval)
                break;
            else if(minval <= n && n <= maxval){
                cnt += (n - minval + 1);
                break;
            }else
                cnt += fac;
            fac *= 10;
        }
        return cnt;
    }
    
};
