/*
* 
* Tag: Graph
* Time: O(n^2)
* Space: O(n + m)
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
using namespace std;

class GraphTravser {
private:
    unordered_map<int, unordered_set<int>> graph;
public:
    GraphTravser(){
        graph.clear();
    }
    
    vector<int> getMinimunNumOfVertices(vector<vector<int>> edges, int numOfNodes){
        graph.clear();
        
        for(vector<int> edge : edges){
            graph[edge[0]].insert(edge[1]);
        }
        
        unordered_set<int> visitedNodes;
        unordered_set<int> ansSet;
        for(int i = 0; i < numOfNodes; ++ i){
            if(visitedNodes.count(i) == 0){
                // revisit nodes in a circle can reduce the answer set. thus curVisitedNodes set is required.
                unordered_set<int> curVisitedNodes;
                ansSet.insert(i);
                dfs(i, i, visitedNodes, curVisitedNodes, ansSet);
            }
        }
        
        vector<int> ans(ansSet.begin(), ansSet.end());
        return ans;
    }

private:
    void dfs(int curNode, int startNode, unordered_set<int> &visitedNodes, unordered_set<int> &curVisitedNodes, unordered_set<int>& ansSet){
        visitedNodes.insert(curNode);
        curVisitedNodes.insert(curNode);
        
        for(int nextNode : graph[curNode]) {
            if(ansSet.count(nextNode) != 0 && nextNode != startNode ){
                ansSet.erase(nextNode);
            }
            
            if(curVisitedNodes.count(nextNode) == 0){
                dfs(nextNode, startNode, visitedNodes, curVisitedNodes, ansSet);
            }
        }
    }
};

int main() {
    GraphTravser gt;
    
    vector<vector<int>> testCase1 = {{0,1},{1,2},{2,1}};
    vector<int> ans = gt.getMinimunNumOfVertices(testCase1, 3);
    assert(ans.size() == 1 && ans[0] == 0);
    
    vector<vector<int>> testCase2 = {{0, 0}, {1, 2}, {2, 0}, {2, 3}, {3, 1}};
    ans = gt.getMinimunNumOfVertices(testCase2, 4);
    assert(ans.size() == 1 && ans[0] != 0);
    
    vector<vector<int>> testCase3 = {{0, 1}, {1, 0}, {2, 1}, {2, 3}, {3, 2}};
    ans = gt.getMinimunNumOfVertices(testCase3, 4);
    assert(ans.size() == 1 );
    
    vector<vector<int>> testCase4 = {{0, 1}, {1, 0}, {2, 1}, {3, 1}, {3, 2}};
    ans = gt.getMinimunNumOfVertices(testCase4, 4);
    assert(ans.size() == 1 );
    
    vector<vector<int>> testCase5 = {{2, 9}, {3, 3}, {3, 5}, {3, 7}, {4, 8}, {5, 8}, {6, 6}, {7, 4}, {8, 7}, {9, 3}, {9, 6}};
    ans = gt.getMinimunNumOfVertices(testCase5, 10);
    assert(ans.size() == 3 );
    
    vector<vector<int>> testCase6 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 8}, {8, 9}, {9, 0}, {5, 1}, {6, 2}, {7, 3}};
    ans = gt.getMinimunNumOfVertices(testCase6, 10);
    assert(ans.size() == 3 );
    return 0;
}
