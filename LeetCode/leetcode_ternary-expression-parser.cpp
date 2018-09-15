/*
*
* Tag: DFS and Data Structure
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    string parseTernary(string expression) {
        string res = "";
        op_top = top = 0;
        stk.resize(expression.size() + 10);
        opstk.resize(expression.size() + 10);
        dfs(expression, 0);
        res = stk[0];
        return res;
    }
    
    void dfs(string &expression, int idx){
        if(idx >= expression.size())
            return ;
        string expr = "";
        char res = 0;
        stk[top ++] = expression[idx ++];
        if(expression[idx] == ':'){
            while(op_top && opstk[op_top - 1] == ':'){
                if(stk[top - 3] == 'T')
                    res = stk[top - 2];
                else
                    res = stk[top - 1];
                top -= 3;
                stk[top ++] = res;
                op_top -= 2;
            }
            opstk[op_top ++] = expression[idx];
            dfs(expression, idx + 1);
            if(top == 1)
                return ;
            if(stk[top - 3] == 'T')
                res = stk[top - 2];
            else
                res = stk[top - 1];
            top -= 3;
            op_top -= 2;
            stk[top ++] = res;
        }else{
            opstk[op_top ++] = expression[idx];
            dfs(expression, idx + 1);
        }
    }
    
private:
    vector<char> stk, opstk;
    int top, op_top;
};
