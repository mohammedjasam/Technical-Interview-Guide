/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long l = 1, r = n;
        int ans = 1;
        while(l <= r){
            long long mid = (l + r)>>1;
            int v = guess((int)mid);
            if(v == 0){
                ans = mid;
                break;
            }else if(v == 1){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};
