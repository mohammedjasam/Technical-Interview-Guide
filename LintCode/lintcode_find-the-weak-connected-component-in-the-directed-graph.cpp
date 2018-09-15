/*
*
* Tag: Data Structure (Union Find)
* Time: O(n)
* Space: O(n)
*/
/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        // Write your code here
        vector<vector<int>> ans;
        if(!nodes.size())
            return ans;
        
        fa.clear();
        dict.clear();
        int n = nodes.size(), cnt = 0;
        for(int i = 0; i < n; ++ i){
            DirectedGraphNode* u = nodes[i];
            int u_lab = u->label;
            if(fa.find(u_lab) != fa.end()){
                continue;
            }
            fa[u_lab] = u_lab;
            ++ cnt;
            dfs(u, u_lab, nodes, cnt);
        }
        
        ans.resize(cnt);
        int idx = 0;
        for(int i = 0; i < n; ++ i){
            int id = nodes[i]->label;
            if(fa[id] == id){
                dict[id] = idx;
                ++ idx;
            }
        }
        
        for(int i = 0; i < n; ++ i){
            int id = nodes[i]->label, t_id;
            if(fa[id] != id){
                int s_id = find(id);
                t_id = dict[s_id];
            }else{
                t_id = dict[id];
            }
            ans[t_id].push_back(id);
        }
        
        for(int i = 0; i < cnt; ++ i)
            sort(ans[i].begin(), ans[i].end());
            
        return ans;
    }
    
    void dfs(DirectedGraphNode* u, int u_lab, vector<DirectedGraphNode*>& nodes, int &cnt){
        int m = u->neighbors.size();
        for(int i = 0; i < m; ++ i){
            DirectedGraphNode* v = u->neighbors[i];
            int v_lab = v->label;
            bool do_dfs = false;
            if(fa.find(v_lab) == fa.end()){
                fa[v_lab] = v_lab;
                ++ cnt;
                do_dfs = true;
            }
            if(find(u_lab) != find(v_lab)){
                -- cnt;
                unionset(u_lab, v_lab);
            }
            if(do_dfs)
                dfs(v, u_lab, nodes, cnt);
        }
    }
    
    int find(int x){
        int s;
        for(s = x; fa[s] != s; s = fa[s]) ;
        while(s != x){
            int tmp = fa[x];
            fa[x] = s;
            x = tmp;
        }
        return s;
    }
    
    void unionset(int a, int b){
        int r1 = find(a), r2 = find(b);
        int tmp = fa[r1] + fa[r2];
        if(fa[r1] > fa[r2]){
            fa[r1] = r2;
        }else{
            fa[r2] = r1;
        }
    }

private:
unordered_map<int,int> fa;
unordered_map<int,int> dict;

};
