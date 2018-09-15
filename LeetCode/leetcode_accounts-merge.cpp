/*
*
* Tag: DFS
* Time: O(n^2 * lgn) where n is the number of emails
* Space: O(n^2)
*/
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        if(accounts.size() == 0){
            return ans;
        }
        
        unordered_map<string, vector<string>> graph;
        unordered_map<string, string> nameOfEmails;
        for(vector<string> account : accounts){
            string name = account[0];
            for(int i = 1; i < account.size(); ++ i){
                string emailFirst = account[i];
                nameOfEmails[emailFirst] = name;
                for(int j = i + 1; j < account.size(); ++ j){
                    string emailSecond = account[j];
                    graph[emailFirst].push_back(emailSecond);
                    graph[emailSecond].push_back(emailFirst);
                }
            }
        }
        
        unordered_set<string> checkedEmails;
        for(pair<string,string> nameOfEmail : nameOfEmails){
            string email = nameOfEmail.first;
            if(checkedEmails.count(email) == 0){
                vector<string> mergedAccount;
                
                dfs(email, mergedAccount, checkedEmails, graph);
                sort(mergedAccount.begin(), mergedAccount.end());
                
                string name = nameOfEmail.second;
                mergedAccount.insert(mergedAccount.begin(), name);
                ans.push_back(mergedAccount);
            }
        }
        
        return ans;
    }
private:
    void dfs(string email, vector<string> &mergedAccount, unordered_set<string> &checkedEmails, unordered_map<string, vector<string>> &graph){
        checkedEmails.insert(email);
        mergedAccount.push_back(email);
        
        for(string nextEmail : graph[email]){
            if(checkedEmails.count(nextEmail) == 0){
                dfs(nextEmail, mergedAccount, checkedEmails, graph);
            }
        }
    }
};
