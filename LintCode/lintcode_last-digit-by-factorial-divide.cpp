/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    int computeLastDigit(long long A, long long B) {
        if(A == B)
            return 1;
        if(B - A >= 10)
            return 0;
        int ans = 1;
        for(long long i = A + 1; i <= B; ++ i){
            int factor = i%10;
            ans = (ans * factor)%10;
        }
        return ans;
    }
};
