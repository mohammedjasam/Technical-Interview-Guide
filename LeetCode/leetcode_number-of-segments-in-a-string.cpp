/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        bool meetSpace = true;
        if(s.size() == 0)
            return res;
        for(int i = 0; i < s.size(); ++ i){
            if(s[i] == ' ')
                meetSpace = true;
            else{
                if(meetSpace)
                    ++ res;
                meetSpace = false;
            }
        }
        return res;
    }
};
