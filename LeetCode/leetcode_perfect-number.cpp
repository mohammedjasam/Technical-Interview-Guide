/*
*
* Tag: Math
* Time: O(n^0.5)
* Space: O(1)
*/
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1)
            return false;
        int sum = 0, n = sqrt(num);
        for(int i = 2; i <= n; ++ i){
            if(num%i == 0)
                sum += (i + (i*i == num?0:num/i));
        }
        ++ sum;
        return sum == num;
    }
};
