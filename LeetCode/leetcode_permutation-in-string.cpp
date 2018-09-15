/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        int n = s1.size(), m = s2.size();
        vector<int> scnt(26), tcnt(26);
        
        for(int i = 0, j = 0; i < m; ++ i){
            if(i < n){
                ++ scnt[s1[i] - 'a'];
            }
            ++ tcnt[s2[i] - 'a'];
            if(i >= n - 1){
                if(i >= n){
                    -- tcnt[s2[j] - 'a'];
                    ++ j;
                }
                if(isPermute(scnt, tcnt))
                    return true;
            }
        }
        
        return false;
    }
private:
    inline bool isPermute(vector<int> &scnt, vector<int> &tcnt){
        for(int i = 0; i < scnt.size(); ++ i){
            if(scnt[i] != tcnt[i])
                return false;
        }
        return true;
    }
};
