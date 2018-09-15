/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size() < 2){
            return true;
        }
        
        vector<int> colorOfNode(graph.size(), -1);
        bool ans = true;
        for(int i = 0; i < graph.size(); ++ i){
            if(colorOfNode[i] == -1) {
                colorOfNode[i] = 0;
                ans &= canSetColorOfNodesReachedByNodeAsBipartite(i, colorOfNode, graph);
                if(!ans){
                    break;
                }
            }
        }
        
        return ans;
    }
    
private:
    bool canSetColorOfNodesReachedByNodeAsBipartite(int startNode, vector<int> &colorOfNode, vector<vector<int>>& graph){
        bool ans = true;
        int colorOfCurrentNode = colorOfNode[startNode];
        for(int i = 0; i < graph[startNode].size(); ++ i){
            int nextNode = graph[startNode][i];
            if(colorOfNode[nextNode] == colorOfNode[startNode]) {
                ans = false;
                break;
            }
            
            if(colorOfNode[nextNode] == -1){
                colorOfNode[nextNode] = (colorOfCurrentNode + 1)%2;
                ans &= canSetColorOfNodesReachedByNodeAsBipartite(nextNode, colorOfNode, graph);
                if(!ans){
                    break;
                }
            }
        }
        
        return ans;
    }
};
