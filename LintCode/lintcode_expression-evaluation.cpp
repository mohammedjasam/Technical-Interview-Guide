/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        // write your code here
        int ans = 0;
        if(!expression.size())
            return ans;
        expression.push_back(")");
        int n = expression.size();
        stk_str.push("(");
        for(int i = 0; i < n; ++ i){
            string val = expression[i];
            if(val[0] >= '0' && val[0] <= '9'){
                int intval = strToint(val);
                stk_int.push(intval); 
            }else{
                getOptRes(val);
            }
        }
        ans = stk_int.top();
        return ans;
    }
    
    void getOptRes(string op){
        int a, b, c;
        string prev_op;
        if(op == "("){
            stk_str.push(op);
        }else if(op == "+" || op == "-"){
            prev_op = stk_str.top();
            if(prev_op != "("){
                stk_str.pop();
                b = stk_int.top();
                stk_int.pop();
                a = stk_int.top();
                stk_int.pop();
                c = cal(a, b, prev_op);
                stk_int.push(c);
            }
            stk_str.push(op);
        }else if(op == "*" || op == "/"){
            prev_op = stk_str.top();
            if(prev_op == "*" || prev_op == "/"){
                stk_str.pop();
                b = stk_int.top();
                stk_int.pop();
                a = stk_int.top();
                stk_int.pop();
                c = cal(a, b, prev_op);
                stk_int.push(c);
            }
            stk_str.push(op);
        }else{
            while(stk_str.top() != "("){
                prev_op = stk_str.top();
                stk_str.pop();
                b = stk_int.top();
                stk_int.pop();
                a = stk_int.top();
                stk_int.pop();
                c = cal(a, b, prev_op);
                stk_int.push(c);
            }
            stk_str.pop();
        }
    }
    
    int strToint(string str){
        int res = 0;
        for(int i = 0; i < str.size(); ++ i){
            res *= 10;
            res += (str[i] - '0');
        }
        return res;
    }
    
    int cal(int a, int b, string op){
        int res = 0;
        if(op == "+")
            res = a+b;
        else if(op == "-")
            res = a - b;
        else if(op == "*")
            res = a*b;
        else
            res = a/b;
        return res;
    }
    
private:
    stack<int> stk_int;
    stack<string> stk_str;
};
