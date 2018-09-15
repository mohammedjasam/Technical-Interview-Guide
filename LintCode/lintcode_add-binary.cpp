/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        string ans;
        if(a=="")
            return b;
        if(b=="")
            return a;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int ia = 0, ib = 0, na = a.size(), nb = b.size(), c = 0, sum = 0;
        for(; ia < na && ib < nb; ++ ia,  ++ ib){
            sum = (a[ia] - '0') + (b[ib] - '0') + c;
            if(sum < 2)
                c = 0;
            else
                c = 1;
            sum%=2;
            ans += ('0' + sum);
        }
        while(ia < na){
            sum = (a[ia] - '0') + c;
            if(sum < 2)
                c = 0;
            else
                c = 1;
            sum%=2;
            ans += ('0' + sum);
            ++ ia;
        }
        while(ib < nb){
            sum = (b[ib] - '0') + c;
            if(sum < 2)
                c = 0;
            else
                c = 1;
            sum%=2;
            ans += ('0' + sum);
            ++ ib;
        }
        if(c)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
