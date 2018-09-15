/*
*
* Tag: DFS
* Time: O(n) where n is the number of unqiue variables
* Space: O(n)
*/
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> query) {
        vector<double> ans(query.size());
        if(!query.size()) {
            return ans;
        }
        
        unordered_map<string, unordered_map<string,double>> mp;
        unordered_set<string> vis;
        mp.clear();
        bool canReach = true;
        double res = 1.0, tmpres;
        for(int i = 0; i < equations.size(); ++ i){
            mp[equations[i].first][equations[i].second] = values[i];
            mp[equations[i].second][equations[i].first] = 1.0/values[i];
        }
        for(int i = 0; i < query.size(); ++ i){
            if(mp.find(query[i].first) == mp.end() || mp.find(query[i].second) == mp.end())
                ans[i] = -1.0;
            else{
                canReach = false;
                tmpres = 1.0;
                res = -1.0;
                vis.clear();
                vis.insert(query[i].first);
                dfs(query[i].first, query[i].second, res, tmpres, canReach, mp, vis);
                ans[i] = res;
            }
        }
        
        return ans;
    }
    
private:
    void dfs(string &sta, string &ends, double &res, double &tmpres, bool &canReach, unordered_map<string, unordered_map<string,double>> &mp, unordered_set<string> &vis){
        if(sta == ends){
            res = tmpres;
            canReach = true;
            return ;
        }
        
        unordered_map<string,double>::iterator it = mp[sta].begin();
        double vres = 1.0;
        string u = "";
        for(; it != mp[sta].end(); ++ it){
            if(vis.find(it->first) != vis.end()){
                continue;
            }
            
            vres = tmpres*it->second;
            u = it->first;
            vis.insert(it->first);
            dfs(u, ends, res, vres, canReach, mp, vis);
            
            if(canReach) {
                break ;
            }
        }
        
        return ;
    }
};
