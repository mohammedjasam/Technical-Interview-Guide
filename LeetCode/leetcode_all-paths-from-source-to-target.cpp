/*
*
* Tag: DFS
* Time: O(m) m is the number of edges of graph
* Space: O(m)
*/
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> allPaths;
        if(graph.size() == 0){
            return allPaths;
        }
        
        int destination = graph.size() - 1;
        vector<int> path;
        dfs(0, destination, path, allPaths, graph);
        
        return allPaths;
    }
    
private:
    void dfs(int curNode, int destination, vector<int> path, vector<vector<int>> &allPaths, vector<vector<int>> &graph){
        path.push_back(curNode);
        
        if(curNode == destination){
            allPaths.push_back(path);
            return ;
        }
        
        for(int nextNode : graph[curNode]){
            dfs(nextNode, destination, path, allPaths, graph);
        }
    }
};
