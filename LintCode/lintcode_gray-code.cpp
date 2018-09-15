/*
*
* Tag: Bit Manipulation
* Time: O(2^n)
* Space: O(2^n)
*/
class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        vector<int> res;
        res.reserve(1<<n);
        res.push_back(0);
        for(int i = 0; i < n; ++ i){
            const int high_bit = 1<<i;
            for(int j = res.size() - 1; j >= 0; -- j){
                res.push_back(high_bit | res[j]);
            }
        }
        return res;
    }
};
