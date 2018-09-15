/*
*
* Tag: BFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param pid: the process id
     * @param ppid: the parent process id
     * @param kill: a PID you want to kill
     * @return: a list of PIDs of processes that will be killed in the end
     */
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        vector<int> ans;
        if(pid.size() == 0)
            return ans;
            
        unordered_map<int, vector<int>> pidRelations = constructProcessRelations(pid, ppid);
        
        queue<int> q;
        q.push(kill);
        while(!q.empty()){
            int curProcess = q.front();
            q.pop();
            ans.push_back(curProcess);
            
            for(int i = 0; i < pidRelations[curProcess].size(); ++ i){
                int nextProcess = pidRelations[curProcess][i];
                q.push(nextProcess);
            }
        }
        
        return ans;
    }
private:
    unordered_map<int, vector<int>> constructProcessRelations(vector<int> &pid, vector<int> &ppid){
        unordered_map<int, vector<int>> pidRelations;
        for(int i = 0; i < pid.size(); ++ i){
            pidRelations[ppid[i]].push_back(pid[i]);
        }
        
        return pidRelations;
    }
};
