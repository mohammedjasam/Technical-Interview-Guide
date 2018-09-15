/*
*
* Tag: Game + DFS (SG Function)
* Time: O(2^n) where n is the length of input string.
* Space: O(2^n)
*/

class Solution {
private:
    unordered_map<string, bool> sg;
public:
    bool canWin(string s) {
        if(s.size() < 2)
            return false;
        init(s);
        if(sg.find(s) != sg.end())
            return sg[s];
        SGFun(s);
        
        return sg[s];
    }
    
private:
    void init(string &s){
        int n = s.size();
        string s1(s.size(), '-');
        sg[s1] = 0;
        string s2 = s1, s3 = s1;
        for(int i = 0; i < n; i += 2)
            s1[i] = '+';
        sg[s1] = 0;
        for(int i = 1; i < n; i += 2)
            s2[i] = '+';
        sg[s2] = 0;
        for(int i = 0; i < n - 1; ++ i){
            s3[i] = s3[i + 1] = '+';
            sg[s3] = 1;
            s3[i] = s3[i + 1] = '-';
        }
    }
    
    bool check(string &s){
        for(int i = 0; i < s.size() - 1; ++ i){
            if(s[i] == '+' && s[i + 1] == '+')
                return true;
        }
        return false;
    }
    
    void SGFun(string &s){
        if(!check(s)){
            sg[s] = 0;
            return ;
        }
        string tmp = s;
        for(int i = 0; i < s.size() - 1; ++ i){
            if(s[i] == '+' && s[i + 1] == '+'){
                tmp[i] = tmp[i + 1] = '-';
                if(sg.find(tmp) == sg.end()){
                    SGFun(tmp);
                }
                if(!sg[tmp]){
                    sg[s] = 1;
                    return ;
                }
                tmp[i] = tmp[i + 1] = '+';
            }
        }
        
        sg[s] = 0;
        return ;
    }
};
