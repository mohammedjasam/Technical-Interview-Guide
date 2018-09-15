/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0){
            return tasks.size();
        }
        
        int ans = 0;
        if(tasks.size() == 0){
            return ans;
        }
        
        priority_queue<int> taskScheduler;
        unordered_map<char,int> countsOfTasks;
        for(char task : tasks){
            ++ countsOfTasks[task];
        }
        for(pair<char,int> countsOfTask : countsOfTasks){
            taskScheduler.push( countsOfTask.second );
        }
        
        int batchSize = 0;
        for(int i = 0; i < tasks.size(); i += batchSize){
            batchSize = 0;
            queue<int> tasksWaitingQueue;
            while(!taskScheduler.empty() && batchSize <= n){
                int taskCount = taskScheduler.top();
                taskScheduler.pop();
                ++ batchSize;
                ++ ans;
                
                if(taskCount > 1) {
                    tasksWaitingQueue.push(taskCount - 1);
                }
            }
            
            if(i + batchSize >= tasks.size()){
                break;
            }
            
            if(batchSize <= n){
                ans += (n - batchSize + 1);
            }
            
            while(!tasksWaitingQueue.empty()){
                taskScheduler.push( tasksWaitingQueue.front() );
                tasksWaitingQueue.pop();
            }
        }
        
        return ans;
    }
};
