/*
*
* Tag: DFS
* Time: O(3^n)
* Space: O(n)
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip;
        dfs(s,0,0,ip,result);
        return result;
    }
    
    void dfs(string s, size_t start, size_t step, string ip, vector<string> &result){
        if(start == s.size() && step == 4){
            ip.resize(ip.size() - 1);
            result.push_back(ip);
            return ;
        }
        
        if(s.size() - start > (4 - step)*3)
            return ;
        if(s.size() - start < (4 - step))
            return ;
            
        int num = 0;
        for(size_t i = start; i < start + 3; i ++){
            num = num*10 + (s[i] - '0');
            
            if(num <= 255){
                ip += s[i];
                dfs(s, i + 1,step + 1,ip+'.',result);
            }
            if(num == 0) break;
        }
    }
};
