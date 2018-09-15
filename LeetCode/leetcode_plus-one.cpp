/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        list<int> newDigits;
        int c = 0, add = 1, sum = 0;
        for(int i = digits.size() - 1; i >= 0; i --){
            sum = digits[i] + c + add;
            add = 0;
            if(sum >= 10){
                c = 1;
            } else {
                c = 0;
            }
            sum %= 10;
            newDigits.push_front(sum);
        }
        if(c){
            newDigits.push_front(1);
        }
        
        vector<int> ans(newDigits.begin(), newDigits.end());
        return ans;
    }
};
