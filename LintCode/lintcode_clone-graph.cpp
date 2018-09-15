/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if(!node)
            return node;
        unordered_map<UndirectedGraphNode *,UndirectedGraphNode *> mp;
        copy_g(mp, node);
        return mp[node];
    }
    
    UndirectedGraphNode *copy_g(unordered_map<UndirectedGraphNode *,UndirectedGraphNode *> &mp, UndirectedGraphNode *node){
        if(mp.find(node) != mp.end())
            return mp[node];
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        mp[node] = new_node;
        for(int i = 0; i < node->neighbors.size(); ++ i){
            new_node->neighbors.push_back(copy_g(mp,node->neighbors[i]));
        }
        return new_node;
    }
};
