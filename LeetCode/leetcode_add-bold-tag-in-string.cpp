/*
*
* Tag: String
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        string ans = "";
        if(s.size() == 0 || dict.size() == 0)
            return s;
        unordered_set<string> st;
        for(int i = 0; i < dict.size(); ++ i)
            st.insert(dict[i]);
        vector<int> tag(s.size());
        for(int i = 0; i < s.size(); ++ i){
            string word = s.substr(i, 1);
            tag[i] = st.count(word) == 0? -1 : i;
            for(int j = i + 1; j < s.size(); ++ j){
                word += s[j];
                if(st.count(word) != 0)
                    tag[i] = j;
            }
        }
        for(int i = 0; i < s.size(); ++ i){
            if(tag[i] == -1)
                ans += s[i];
            else{
                ans += "<b>";
                int j = i, bnd = tag[i];
                dfs(tag, i, bnd, s.size());
                ans += s.substr(i, bnd - i + 1);
                i = bnd;
                ans += "</b>";
            }
        }
        return ans;
    }
private:
    inline void dfs(vector<int> &tag, int idx, int &bnd, int n){
        while(idx <= bnd && bnd < n){
            bnd = max(bnd, tag[idx]);
            ++ idx;
        }
        if(bnd >= n - 1 || tag[bnd + 1] == -1)
            return ;
        bnd = tag[bnd + 1];
        dfs(tag, tag[bnd + 1], bnd, n);
    }
};
