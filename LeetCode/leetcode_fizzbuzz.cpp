/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        if(!n)
            return ans;
        ans.resize(n);
        string tmp = "";
        for(int i = 0; i < n; ++ i){
            tmp = "";
            if((i + 1)%3 != 0 && (i + 1)%5 != 0)
                tmp = to_string((i+1));
            if((i + 1)%3 == 0)
                tmp += "Fizz";
            if((i + 1)%5 == 0)
                tmp += "Buzz";
            ans[i] = tmp;
        }
        return ans;
    }
};
