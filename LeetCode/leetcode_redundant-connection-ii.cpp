/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
private:
    bool hasCircle;
    vector<int> stackOfEdgeIds;
    int stackTop;
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        if(edges.size() == 0){
            return ans;
        }
        
        stackOfEdgeIds.resize(edges.size() + 1);
        stackTop = 0;
        
        unordered_map<int, vector<pair<int,int>>> tree, reversedTree;
        int maxNodeId = 0;
        int nodeWithMultiParents = -1;
        for(int i = 0; i < edges.size(); ++ i){
            tree[edges[i][0]].push_back( make_pair(edges[i][1], i) );
            reversedTree[edges[i][1]].push_back( make_pair(edges[i][0], i) );
            if(reversedTree[edges[i][1]].size() > 1){
                nodeWithMultiParents = edges[i][1];
            }
            maxNodeId = max(maxNodeId, max(edges[i][0], edges[i][1]));
        }
        
        vector<bool> inStack(maxNodeId + 1, false);
        for(auto it = tree.begin(); it != tree.end(); ++ it){
            if(it->second.size() == 0){
                continue;
            }
            
            hasCircle = false;
            dfs(it->first, tree, inStack);
            if(hasCircle){
                break;
            }
        }
        
        int maxEdgeIndex = 0;
        if(hasCircle){
            if(nodeWithMultiParents == -1){
                for(int i = 0; i < stackTop; ++ i){
                    maxEdgeIndex = max(maxEdgeIndex, stackOfEdgeIds[i]);
                }
            } else {
                for(int i = 0; i < stackTop; ++ i){
                    if(stackOfEdgeIds[i] == reversedTree[nodeWithMultiParents][0].second || stackOfEdgeIds[i] == reversedTree[nodeWithMultiParents][1].second) {
                        maxEdgeIndex = stackOfEdgeIds[i] == reversedTree[nodeWithMultiParents][0].second ? reversedTree[nodeWithMultiParents][0].second : reversedTree[nodeWithMultiParents][1].second;
                    }
                }
            }
        } else {
            maxEdgeIndex = max(reversedTree[nodeWithMultiParents][0].second, reversedTree[nodeWithMultiParents][1].second);
        }
        ans = edges[maxEdgeIndex];
        
        return ans;
    }

private:
    void dfs(int node, unordered_map<int, vector<pair<int,int>>>& tree, vector<bool> &inStack){
        if(inStack[node]) {
            hasCircle = true;
            return ;
        }
        
        if(tree.count(node) == 0 || tree[node].size() == 0){
            return ;
        }
        
        inStack[node] = true;
        for(pair<int,int> edge : tree[node]){
            stackOfEdgeIds[stackTop ++] = edge.second;
            dfs(edge.first, tree, inStack);
            if(hasCircle){
                return ;
            }
            -- stackTop;
        }
        
        inStack[node] = false;
        return ;
    }
};
