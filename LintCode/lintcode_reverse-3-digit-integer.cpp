/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param number: A 3-digit number.
     * @return: Reversed number.
     */
    int reverseInteger(int number) {
        int ans = 0;
        
        while(number > 0){
            ans = (ans*10) + (number%10);
            number /= 10;
        }
        
        return ans;
    }
};
