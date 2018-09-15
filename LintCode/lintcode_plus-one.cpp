/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        vector<int> ans;
        if(!digits.size()){
            ans.push_back(1);
            return ans;
        }
        int c = 1, sum = 0, n = digits.size();
        vector<int> tmpans(n + 1);
        int idx = n, len = 0;
        for(int i = n - 1; i >= 0; -- i, -- idx, ++ len){
            sum = c + digits[i];
            c = sum/10;
            sum %= 10;
            tmpans[idx] = sum;
        }
        if(c){
            tmpans[idx --] = c;
            ++ len;
        }
        ans.resize(len);
        -- len;
        for(int i = n; i > idx; -- i, -- len)
            ans[len] = tmpans[i];
        return ans;
    }
};
