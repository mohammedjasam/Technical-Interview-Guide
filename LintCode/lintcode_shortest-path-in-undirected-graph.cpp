/*
*
* Tag: BFS
* Time: O(n)
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
     * @param graph: a list of Undirected graph node
     * @param A: nodeA
     * @param B: nodeB
     * @return:  the length of the shortest path
     */
    int shortestPath(vector<UndirectedGraphNode*> graph, UndirectedGraphNode* A, UndirectedGraphNode* B) {
        
        queue<pair<UndirectedGraphNode*,int>> q;
        q.push(make_pair(A, 0));
        
        unordered_set<int> visitedNode;
        visitedNode.insert(A->label);
        
        int shortestPath = 0;
        while(!q.empty()){
            pair<UndirectedGraphNode*, int> curNode = q.front();
            q.pop();
            
            UndirectedGraphNode* curGraphNode = curNode.first;
            int curPath = curNode.second;
            if(curGraphNode->label == B->label){
                shortestPath = curPath;
                break;
            }
            
            for(int i = 0; i < curGraphNode->neighbors.size(); ++ i){
                UndirectedGraphNode* nextGraphNode = curGraphNode->neighbors[i];
                int nextLabel = nextGraphNode->label;
                if(visitedNode.count(nextLabel) == 0){
                    visitedNode.insert(nextLabel);
                    q.push(make_pair(nextGraphNode, curPath + 1));
                }
            }
        }
        
        return shortestPath;
    }
};
