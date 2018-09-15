/*
*
* Tag: BFS
* Time: O(n*2^n)
* Space: O(n*2^n)
*/
class Solution {
private:
    vector<vector<int>> dp;
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size() == 0 || graph[0].size() == 0){
            return 0;
        }
        
        init(graph);
        
        int numOfNodes = graph.size();
        queue<pair<int,int>> q;
        for(int i = 0; i < numOfNodes; ++ i){
            dp[(1<<i)][i] = 0;
            q.push(make_pair((1<<i), i));
        }
        
        int finalState = (1<<numOfNodes) - 1;
        while(!q.empty()){
            pair<int,int> state = q.front();
            q.pop();
            
            int curState = state.first, curNode = state.second;
            if(curState == finalState){
                return dp[curState][curNode];
            }
            
            int distance = dp[curState][curNode];
            for(int t : graph[curNode]){
                int nextState = curState|(1<<t);
                if(dp[nextState][t] == -1 || dp[nextState][t] > distance + 1){
                    dp[nextState][t] = distance + 1;
                    q.push(make_pair(nextState, t));
                }
            }
        }      

        return -1;
    }
    
private:
    void init(vector<vector<int>>& graph){
        int numOfNodes = graph.size();
        
        int numOfRows = (1<<numOfNodes) - 1;
        dp.resize(numOfRows + 1);
        for(int i = 0; i <= numOfRows; ++ i){
            vector<int> column(numOfNodes, -1);
            dp[i] = column;
        }
    }
};
