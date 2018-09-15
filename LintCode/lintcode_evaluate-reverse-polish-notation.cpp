/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        int ans = 0;
        if(tokens.size() == 0)
            return ans;
        int n = tokens.size();
        for(int i = 0; i < n; ++ i){
            if(tokens[i].size() == 1 && (tokens[i][0]<'0' || tokens[i][0]>'9')){
                Cal(tokens[i][0]);
            }else{
                int val = StrtoNum(tokens[i]);
                num_stk.push(val);
            }
        }
        return num_stk.top();
    }
    
    int StrtoNum(string val){
        int res = 0, idx = 0;
        bool isneg = false;
        if(val[0] == '-'){
            ++ idx;
            isneg = true;
        }
        for(; idx < val.size(); ++ idx){
            res = (res * 10) + (val[idx] - '0');
        }
        return isneg?-res:res;
    }
    
    void Cal(char op){
        int res = 0, a, b;
        b = num_stk.top();
        num_stk.pop();
        a = num_stk.top();
        num_stk.pop();
        switch(op){
            case '+': res = a + b; break;
            case '-': res = a - b; break;
            case '*': res = a * b; break;
            case '/': res = a / b; break;
        }
        num_stk.push(res);
        return ;
    }
private:
stack<int> num_stk;
};
