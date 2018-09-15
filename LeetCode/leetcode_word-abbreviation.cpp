/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        vector<string> ans;
        if(dict.size() == 0)
            return ans;
        ans.resize(dict.size());
        if(dict.size() == 1){
            if(dict[0].size() <= 3)
                ans[0] = dict[0];
            else
                ans[0] = dict[0][0] + to_string(dict[0].size() - 2) + dict[0][dict[0].size() - 1];
            return ans;
        }
        string res = "", tmpres = "";
        bool isfirst = true;
        int n = dict.size();
        for(int i = 0; i < n; ++ i){
            isfirst = true;
            for(int j = 0; j < n; ++ j){
                if(i != j){
                    tmpres = calcAbbrev(dict[i], dict[j]);
                    if(isfirst)
                        res = tmpres;
                    else{
                        if(tmpres.size() > res.size())
                            res = tmpres;
                    }
                    isfirst = false;
                }
            }
            ans[i] = res;
        }
        return ans;
    }
private:
    string calcAbbrev(string s, string t){
        if(s.size() <= 3)
            return s;
        string res = "";
        int n = s.size(), m = t.size();
        if(s[0] != t[0] || s[n - 1] != t[m - 1] || t.size() != s.size()){
            res = s[0] + to_string(n - 2) + s[n - 1];
        }else{
            int pre_len = 1;
            while(pre_len < n && pre_len < m && s.substr(0, pre_len) == t.substr(0, pre_len))
                ++ pre_len;
            if(pre_len <= n - 3)
                res = s.substr(0, pre_len) + to_string(n - pre_len - 1) + s[n - 1];
            else{
                res = s;
            }
        }
        return res;
    }
};
