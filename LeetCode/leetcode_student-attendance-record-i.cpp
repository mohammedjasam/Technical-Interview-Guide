/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool checkRecord(string s) {
        if(s.size() == 0)
            return true;
        int cntA = 0, cntL = 0, n = s.size();
        for(int i = 0; i < n; ++ i){
            if(s[i] == 'L'){
                ++ cntL;
            }else{
                cntL = 0;
                if(s[i] == 'A')
                    ++ cntA;
            }
            if(cntA > 1 || cntL > 2)
                return false;
        }
        return true;
    }
};
