/*
*
* See A* Solution
* Tag: BFS
* Time: O(rc*(rc)!)
* Space: O(rc*(rc)!)
*/
class Solution {
private:
    const string finalBoardState = "123450";
    
    vector<vector<int>> swappedToPostions;
    
public:
    Solution() {
        swappedToPostions.resize(6);
        
        swappedToPostions[0] = {1, 3};
        swappedToPostions[1] = {0, 2, 4};
        swappedToPostions[2] = {1, 5};
        swappedToPostions[3] = {0, 4};
        swappedToPostions[4] = {1, 3, 5};
        swappedToPostions[5] = {2, 4};
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        if(board.size() == 0){
            return 0;
        }
        
        string initialBoardState = serializeBoard(board);
        
        queue<pair<string,int>> q;
        q.push(make_pair(initialBoardState, 0));
        
        unordered_set<string> visitedBoardStates;
        visitedBoardStates.insert(initialBoardState);
        
        int ans = -1;
        while(!q.empty()){
            pair<string,int> curState = q.front();
            q.pop();
            
            string curBoardState = curState.first;
            int numOfStep = curState.second;
            if(curBoardState == finalBoardState){
                ans = numOfStep;
                break;
            }
            
            int moveablePos = 0;
            for(int i = 0; i < curBoardState.size(); ++ i){
                if(curBoardState[i] == '0') {
                    moveablePos = i;
                    break;
                }
            }
            
            for(int nextPos : swappedToPostions[moveablePos]){
                string nextBoardState = curBoardState;
                swap(nextBoardState[moveablePos], nextBoardState[nextPos]);

                if(visitedBoardStates.count(nextBoardState) == 0){
                    visitedBoardStates.insert(nextBoardState);
                    q.push(make_pair(nextBoardState, numOfStep + 1));
                }
            }
        }
        
        return ans;
    }
    
private:
    string serializeBoard(vector<vector<int>>& board){
        string state = "";
        
        for(int i = 0; i < board.size(); ++ i){
            for(int j = 0; j < board[i].size(); ++ j){
                state += to_string(board[i][j]);
            }
        }
        
        return state;
    }
};
