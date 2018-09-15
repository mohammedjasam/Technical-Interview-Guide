/*
*
* Tag: DFS
* Time: O(n + m)
* Space: O(n)
*/
/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        // Write your code here
        unordered_set<int> vis;
        vector<vector<int>> ans;
        for(int i = 0; i < nodes.size(); ++ i){
            int u = nodes[i]->label;
            if(vis.find(u) == vis.end()){
                vector<int> tmp_ans;
                tmp_ans.push_back(u);
                vis.insert(u);
            //    vector<UndirectedGraphNode *> vec_v = nodes[i]->neighbors;
                dfs(nodes[i], nodes, vis, tmp_ans);
                sort(tmp_ans.begin(), tmp_ans.end());
                ans.push_back(tmp_ans);
            }
        }
        return ans;
    }
    
    void dfs(UndirectedGraphNode* u, vector<UndirectedGraphNode*>& nodes, unordered_set<int> &vis, vector<int> &tmp_ans){
        for(int i = 0; i < u->neighbors.size(); ++ i){
            int v = u->neighbors[i]->label;
            if(vis.find(v) == vis.end()){
                vis.insert(v);
                tmp_ans.push_back(v);
                dfs(u->neighbors[i], nodes, vis, tmp_ans);
            }
        }
    }
};
