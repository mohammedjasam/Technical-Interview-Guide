/*
*
* Tag: DFS
* Time: O(n(k^n))
* Space: O(n(k^n))
*/
class Solution {
public:
    string crackSafe(int n, int k) {
        int total = pow(k, n);
        string code = "";
        for(int i = 0; i < n; ++ i){
            code += "0";
        }
        
        unordered_set<string> usedCodes;
        usedCodes.insert(code);
        
        dfs(code, total, usedCodes, n, k);
        
        return code;
    }
    
private:
    bool dfs(string &code, int total, unordered_set<string> &usedCodes, int n, int k){
        if(usedCodes.size() == total){
            return true;
        }
        
        string prefix = code.substr(code.size() - n + 1);
        for(int i = 0; i < k; ++ i){
            string nextSuffix = prefix + (char)(i + '0');
            if(usedCodes.count(nextSuffix) == 0){
                usedCodes.insert(nextSuffix);
                code += (char)(i + '0');
                if(dfs(code, total, usedCodes, n, k)){
                    return true;
                } else {
                    usedCodes.erase(nextSuffix);
                    code.pop_back();
                }
            }
        }
        
        return false;
    }
};
