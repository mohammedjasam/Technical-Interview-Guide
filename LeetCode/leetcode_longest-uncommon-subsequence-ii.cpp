/*
*
* Tag: DFS
* Time: O(m*2^n)
* Space: O(m*2^n)
*/
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        if(strs.size() == 0)
            return ans;
        unordered_set<string> vis, allst, vec_s;
        unordered_set<string>::iterator it;
        unordered_map<string,int> dict;
        if(init(dict,strs,vec_s) == false)
            return ans;
        for(int i = 0; i < strs.size(); ++ i){
            if(vec_s.find(strs[i]) == vec_s.end()){
                calcAllset(allst, strs[i]);
            }
        }
        
        for(it = vec_s.begin(); it != vec_s.end(); ++ it){
            string tmp = "", s = *it;
            vis.clear();
            dfs(vis, allst, tmp, s, 0, ans, vec_s);
        }
        
        return ans;
    }
private:
    bool check(string &s, unordered_set<string> &vec_s, string &v){
        unordered_set<string>::iterator it;
        for(it = vec_s.begin(); it != vec_s.end(); ++ it){
            string u = *it;
            if(u != s){
                int i = 0, j = 0;
                while(i < u.size() && j < v.size()){
                    if(u[i] == v[j])
                        ++ j;
                    ++ i;
                }
                if(j >= v.size())
                    return false;
            }
        }
        return true;
    }

    void dfs(unordered_set<string> &vis, unordered_set<string> &allst, string &tmp, string &s, int sta, int &ans, unordered_set<string> &vec_s){
        for(int i = sta; i < s.size(); ++ i){
            string newtmp = tmp + s[i];
            if(allst.find(newtmp) == allst.end() && check(s, vec_s, newtmp)){
                ans = max(ans, (int)newtmp.size());
            }
            if(vis.find(newtmp) == vis.end()){
                vis.insert(newtmp);
                dfs(vis, allst, newtmp, s, i + 1, ans, vec_s);
            }
        }
    }

    void dfsAllst(unordered_set<string> &allst, string &s, string &strs, int sta){
        for(int i = sta; i < strs.size(); ++ i){
            string tmp = s + strs[i];
            allst.insert(tmp);
            dfsAllst(allst, tmp, strs, i + 1);
        }
    }

    void calcAllset(unordered_set<string> &allst, string &strs){
        for(int i = 0; i < strs.size(); ++ i){
            string s = "";
            s.append(1, strs[i]);
            allst.insert(s);
            dfsAllst(allst, s, strs, i + 1);
        }
    }

    bool init(unordered_map<string,int> &dict, vector<string>& strs, unordered_set<string> &vec_s){
        dict.clear();
        for(int i = 0; i < strs.size(); ++ i)
            ++ dict[strs[i]];
        bool hasCandidate = false;
        unordered_map<string,int>::iterator it;
        string tmp;
        for(it = dict.begin(); it != dict.end(); ++ it){
            if(it->second == 1){
                tmp = it->first;
                vec_s.insert(tmp);
                hasCandidate = true;
            }
        }
        return hasCandidate;
    }
};
