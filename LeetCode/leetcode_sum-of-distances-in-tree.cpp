/*
*
* TODO
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
class Solution { 
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<int> sumOfDistances;
        if(N == 0){
            return sumOfDistances;
        }
        
        vector<vector<int>> tree(N);
        for(vector<int> edge : edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        
        sumOfDistances.resize(N);
        vector<int> countOfDescendants(N, 1);
        dfsToCountNumOfDescendants(0, -1, countOfDescendants, sumOfDistances, tree);
        dfsToUpdateSumOfDistances(0, -1, countOfDescendants, sumOfDistances, tree);
        
        return sumOfDistances;
    }

private:
    void dfsToCountNumOfDescendants(int node, int parent, vector<int> &countOfDescendants, vector<int> &sumOfDistances, vector<vector<int>> &tree){
        for(int child : tree[node]){
            if(child == parent){
                continue;
            }
            
            dfsToCountNumOfDescendants(child, node, countOfDescendants, sumOfDistances, tree);
            countOfDescendants[node] += countOfDescendants[child];
            sumOfDistances[node] += sumOfDistances[child] + countOfDescendants[child];
        }
    }
    
    void dfsToUpdateSumOfDistances(int node, int parent, vector<int> &countOfDescendants, vector<int> &sumOfDistances, vector<vector<int>> &tree){
        for(int child : tree[node]){
            if(child == parent){
                continue;
            }
            
            sumOfDistances[child] = sumOfDistances[node] - countOfDescendants[child] + (tree.size() - countOfDescendants[child]);
            dfsToUpdateSumOfDistances(child, node, countOfDescendants, sumOfDistances, tree);
        }
    }
};
