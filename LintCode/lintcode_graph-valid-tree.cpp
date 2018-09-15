/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        if(n > 1 && !edges.size())
            return false;
        if(n <= 2)
            return true;
        unordered_map<int,unordered_set<int>> mp;
        for(int i = 0; i < edges.size(); ++ i){
            int u = edges[i][0], v = edges[i][1];
            mp[u].insert(v);
            mp[v].insert(u);
        }
        vis.resize(n);
        istree = true;
        dfs(-1, 0, mp);
        for(int i = 0; i < n; ++ i){
            if(!vis[i]){
                istree = false;
                break;
            }
        }
        
        return istree;
    }
private:
    void dfs(int u, int v, unordered_map<int,unordered_set<int>> &mp){
        vis[v] = 1;
        unordered_set<int>::iterator it = mp[v].begin();
        for(; it != mp[v].end(); ++ it){
            if(vis[*it] && *it != u){
                istree = false;
                return ;
            }
            if(!vis[*it]){
                dfs(v, *it, mp);
                if(!istree)
                    return ;
            }
        }
    }
private:
vector<bool> vis;
bool istree;
};
