/*
*
* Tag: BFS
* Time: O(10^n)
* Space: O(10^n)
*/
class Solution {
public:
    /**
     * @param deadends: the list of deadends
     * @param target: the value of the wheels that will unlock the lock
     * @return: the minimum total number of turns 
     */
    int openLock(vector<string> &deadends, string &target) {
        string start = "0000";
        pair<string,int> initState = make_pair(start, 0);
        int ans = -1;
        
        queue<pair<string,int>> q;
        q.push(initState);
        
        vector<bool> stateList(10010, false);
        stateList[0] = true;
        for(int i = 0; i < deadends.size(); ++ i){
            if(deadends[i] == start)
                return ans;
            int state = stoi(deadends[i]);
            stateList[state] = true;
        }
        
        while(!q.empty()) {
            pair<string,int> curState = q.front();
            q.pop();
            
            string curStateString = curState.first;
            int curSteps = curState.second;
            if(curStateString == target) {
                ans = curSteps;
                break;
            }
            
            for(int i = 0; i < 4; ++ i){
                for(int j = 0; j < 2; ++ j){
                    string nextStateString = curStateString;
                    nextStateString[i] = (((nextStateString[i] - '0') + op[j] + 10)%10 + '0');
                    int nextStateValue = stoi(nextStateString);
                    if(stateList[nextStateValue] == false){
                        stateList[nextStateValue] = true;
                        q.push(make_pair(nextStateString, curSteps + 1));
                    }
                }
            }
        }
        
        return ans;
    }

private:
    int op[2] = {1, -1};
};
