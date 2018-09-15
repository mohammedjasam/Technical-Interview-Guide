/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        if(graph.size() == 0){
            return ans;
        }
        
        unordered_set<int> terminateStates;
        for(int i = 0; i < graph.size(); ++ i){
            if(graph[i].size() == 0){
                terminateStates.insert(i);
            }
        }
        
        int numOfNodes = graph.size();
        vector<bool> visitedNodes(numOfNodes, false);
        unordered_set<int> nodesInStack;
        unordered_set<int> unSafeStates;
        for(int i = 0; i < graph.size(); ++ i){
            if(!visitedNodes[i]){
                dfs(i, graph, visitedNodes, unSafeStates, nodesInStack, terminateStates);
            }
        }
        
        for(int i = 0; i < graph.size(); ++ i){
            if(unSafeStates.count(i) == 0){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
    
private:
    void dfs(int currentNode, vector<vector<int>>& graph, vector<bool> &visitedNodes, unordered_set<int> &unSafeStates, unordered_set<int> &nodesInStack, unordered_set<int> &terminateStates) {
        visitedNodes[currentNode] = true;
        if(graph[currentNode].size() == 0){
            return ;
        }
        
        nodesInStack.insert(currentNode);
        for(int nextNode : graph[currentNode]){
            if(!visitedNodes[nextNode]){
                dfs(nextNode, graph, visitedNodes, unSafeStates, nodesInStack, terminateStates);
            } else if(nodesInStack.count(nextNode) != 0) {
                unSafeStates.insert(nodesInStack.begin(), nodesInStack.end());
            }
            
            if(unSafeStates.count(nextNode) != 0){
                unSafeStates.insert(currentNode);
            }
        }
        nodesInStack.erase(currentNode);
        
        return ;
    }
};
