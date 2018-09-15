/*
*
* Tag: Bit Manipulation
* Time: O(max(lga, lgb))
* Space: O(1)
*/
class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0, c = 0, i = 0;
        bool twoneg = false, largepos = false;
        if(a < 0 && b < 0){
            a = -a;
            b = -b;
            twoneg = true;
        }else if((a > 0 && b < 0 && a > -b) || (a < 0 && b > 0 && -a < b) ){
            a = -a;
            b = -b;
            largepos = true;
        }
        while(i < 32){
            int tmpa = a&(1<<i), tmpb = b&(1<<i);
            if((tmpa^tmpb) != 0){
                if(c == 0)
                    ans |= (1<<i);
            }else{
                if(c == 1){
                    ans |= (1<<i);
                }
                if(tmpa){
                    c = 1;
                }else{
                    c = 0;
                }
            }
            ++ i;
        }
        if(twoneg || largepos)
            ans = -ans;
        return ans;
    }
};
