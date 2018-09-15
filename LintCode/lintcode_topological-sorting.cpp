/*
*
* Tag: Graph Theory
* Time: O(nm)
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
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<DirectedGraphNode*> ans;
        if(!graph.size())
            return ans;
        unordered_map<DirectedGraphNode*, int> dict;
        for(int i = 0; i < graph.size(); ++ i){
            DirectedGraphNode* u = graph[i];
            if(dict.find(u) == dict.end())
                dict[u] = 0;
            for(int j = 0; j < u->neighbors.size(); ++ j){
                DirectedGraphNode* v = u->neighbors[j];
                if(dict.find(v) == dict.end())
                    dict[v] = 1;
                else
                    ++ dict[v];
            }
        }
        vector<DirectedGraphNode*> q;
        int front = 0, rear = 0;
        for(unordered_map<DirectedGraphNode*, int>::iterator it = dict.begin(); it != dict.end(); ++ it){
            if(it->second == 0){
                q.push_back(it->first);
                ++ rear;
            }
        }
        
        while(front < rear){
            DirectedGraphNode* u = q[front ++];
            ans.push_back(u);
            for(int i = 0; i < u->neighbors.size(); ++ i){
                DirectedGraphNode* v = u->neighbors[i];
                -- dict[v];
                if(dict[v] == 0){
                    q.push_back(v);
                    ++ rear;
                }
            }
        }
        
        return ans;
    }
};
