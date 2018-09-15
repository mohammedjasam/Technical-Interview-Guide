/*
*
* Tag: Greedy
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0)
            return ans;
        vector<string> vec_strs(strs.size());
        string tmpstr = "";
        char maxch = 0;
        int chcnt = 0;
        for(int i = 0; i < strs.size(); ++ i){
            vec_strs[i] = max(strs[i], reverseStr(strs[i]));
            tmpstr += strs[i];
            for(int j = 0; j < strs[i].size(); ++ j){
                if(strs[i][j] > maxch){
                    maxch = strs[i][j];
                    chcnt = 1;
                }else if(strs[i][j] == maxch)
                    ++ chcnt;
            }
        }
        if(chcnt == tmpstr.size()){
            ans = tmpstr;
        }else{
            for(int i = 0; i < strs.size(); ++ i){
                for(int j = 0; j < strs[i].size(); ++ j){
                    if(strs[i][j] == maxch){
                        tmpstr = "";
                        for(int l = j; l < strs[i].size(); ++ l)
                            tmpstr += strs[i][l];
                        addResStr(tmpstr, vec_strs, i);
                        tmpstr += strs[i].substr(0, j);
                        ans = max(ans, tmpstr);
                        
                        tmpstr = "";
                        for(int l = j; l >= 0; -- l)
                            tmpstr += strs[i][l];
                        addResStr(tmpstr, vec_strs, i);
                        for(int l = strs[i].size() - 1; l >= j + 1; -- l)
                            tmpstr += strs[i][l];
                        ans = max(ans, tmpstr);
                    }
                }
            }
        }
        return ans;
    }
private:
    string reverseStr(string s){
        string res = s;
        reverse(res.begin(), res.end());
        return res;
    }
    
    void addResStr(string &res, vector<string> &vec_strs, int start){
        for(int k = (start + 1)%vec_strs.size(); k != start; k = (k + 1)%vec_strs.size()){
            res += vec_strs[k];
        }
    }
};
