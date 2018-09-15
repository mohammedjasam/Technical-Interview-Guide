/*
*
* Tag: Math
* Time: O(10^n)
* Space: O(1)
*/
class Solution {
private:
    inline long long calPow(int b, int n){
        long long res = 1;
        while(n --)
            res *= b;
        return res;
    }
    
    inline long long getPalindromeNum(int val){
        long long res = val;
        while(val){
            res = res*10 + val%10;
            val /= 10;
        }
//        printf("%lld\n",res);
        return res;
    }
    
public:
    int largestPalindrome(int n) {
        int ans = 0;
        long long a = 0,  b = 0;
        if(n == 1)
            ans = 9;
        else if(n%2 == 1){
            long long upbnd = calPow(10, n) - 1, lwbnd = upbnd/10;
            long long maxval = upbnd*upbnd;
            int res = maxval/calPow(10, n) + 1;
            while(res --){
                long long tmpRes = getPalindromeNum(res);
                for(long long i = upbnd; i >= lwbnd; -- i){
                    if(tmpRes/i > upbnd || i*i < tmpRes)
                        break;
                    if(tmpRes%i == 0){
                        printf("%lld %lld %lld\n",i,tmpRes/i,tmpRes);
                        ans = (int)(tmpRes%1337);
                        break;
                    }
                }
                if(ans > 0)
                    break;
            }
        }else{
            for(int i = 0; i < n; ++ i){
                a = (a*10 + 9)%1337;
                b = (b*10)%1337;
                if(i < n/2)
                    b = (b + 9)%1337;
                else if(i == n - 1)
                    b = (b + 1)%1337;
            }
            ans = (a*b)%1337;
        }
        return ans;
    }
};
