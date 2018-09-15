/*
*
* Tag: Implementation
* Time: ?
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        if(n <= 0)
            return false;
        unordered_set<int> st;
        while(n != 1){
            int m = 0;
            while(n){
                int t = n%10;
                m += t*t;
                n/=10;
            }
            if(st.find(m) != st.end())
                return false;
            if(m == 1)
                break;
            st.insert(m);
            n = m;
        }
        return true;
    }
};
