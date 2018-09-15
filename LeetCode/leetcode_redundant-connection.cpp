/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
private:
    bool shouldUpdateIndexOfRedundantConnection;
    int indexOfRedundantConnection;
    int startNodeOfCircle;
public:
    Solution(){
        shouldUpdateIndexOfRedundantConnection = false;
        indexOfRedundantConnection = 0;
        startNodeOfCircle = 0;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        if(edges.size() == 0){
            return ans;
        }
                
        vector<vector<pair<int,int>>> graph = buildGraph(edges);
        unordered_set<int> visitedNode;
        dfs(0, 1, graph, visitedNode);
                
        ans = edges[indexOfRedundantConnection];
        return ans;
    }
private:
    vector<vector<pair<int,int>>> buildGraph(vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> graph(edges.size() + 1);
        for(int i = 0; i < edges.size(); ++ i){
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back( make_pair(v, i) );
            graph[v].push_back( make_pair(u, i) );
        }
        
        return graph;
    }
    
    void dfs(int lastNode, int currentNode, vector<vector<pair<int,int>>> &graph, unordered_set<int> &visitedNode){
        if(visitedNode.count(currentNode) != 0){
            shouldUpdateIndexOfRedundantConnection = true;
            startNodeOfCircle = currentNode;
            return ;
        }
        
        visitedNode.insert(currentNode);
        
        for(pair<int,int> edge : graph[currentNode]){
            int nextNode = edge.first, indexOfEdge = edge.second;
            if(nextNode == lastNode){
                continue;
            }
            
            dfs(currentNode, nextNode, graph, visitedNode);
            if(shouldUpdateIndexOfRedundantConnection){
                indexOfRedundantConnection = max(indexOfRedundantConnection, indexOfEdge);
                if(startNodeOfCircle == currentNode){
                    shouldUpdateIndexOfRedundantConnection = false;
                }
                break;
            }
        }
        
        return ;
    }
};
