/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL){
            return NULL;
        }
        
        unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> clone;
        copy(node, clone);
        return clone[node];
    }
    
    UndirectedGraphNode *copy(UndirectedGraphNode *node, unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> &clone){
        if(clone.find(node) != clone.end()){
            return clone[node];
        }
        
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        clone[node] = new_node;
        for(int i = 0; i < node->neighbors.size(); ++ i){
            new_node->neighbors.push_back(copy(node->neighbors[i], clone));
        }
        
        return new_node;
    }
};
