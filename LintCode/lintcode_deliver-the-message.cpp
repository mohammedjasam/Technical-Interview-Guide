/*
*
* Tag: BFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
private:
    const int CEO = 0;
    
public:
    /**
     * @param t: the time of each employee to pass a meeage
     * @param subordinate: the subordinate of each employee
     * @return: the time of the last staff recieve the message
     */
    int deliverMessage(vector<int> &t, vector<vector<int>> &subordinate) {
        int numOfPersons = t.size();
        int ans = 0;
        if(numOfPersons == 0)
            return ans;
        
        vector<int> receiveMessageTime(numOfPersons + 1, 0);
        queue<int> messageSenders;
        messageSenders.push(CEO);
        while(!messageSenders.empty()) {
            int currentSender = messageSenders.front();
            messageSenders.pop();
            for(int i = 0; i < subordinate[currentSender].size() && subordinate[currentSender][i] != -1; ++ i){
                int nextSender = subordinate[currentSender][i];
                receiveMessageTime[nextSender] = receiveMessageTime[currentSender] + t[currentSender];
                messageSenders.push(nextSender);
                ans = max(ans, receiveMessageTime[nextSender]);
            }
        }
        
        return ans;
    }
};
