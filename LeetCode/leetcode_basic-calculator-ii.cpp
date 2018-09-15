/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(n)
*/
class Solution {
private:
    stack<int> numStack;
    stack<char> opStack;
    
public:
    int calculate(string s) {
        if(!s.size()) {
            return 0;
        }
        
        s+='#';
        
        int n = s.size();
        for(int i = 0; i < n; ++ i){
            while(i < n && s[i] == ' ') {
                ++ i;
            }
            if(i >= n) {
                break;
            }
            
            if(s[i] >= '0' && s[i] <= '9'){
                string val = "";
                while(i < n && s[i] >= '0' && s[i] <= '9'){
                    val += s[i];
                    ++ i;
                }
                numStack.push(stoi(val));
                -- i;                
            }else{
                getOptRes(s[i]);                
            }
        }
        
        return numStack.top();
    }
    
    void getOptRes(char op){
        if(opStack.empty()) {
            opStack.push(op);
            return ;
        }
        
        int a, b, c;
        char prev_op;
        if(op == '+' || op == '-'){
            while(!opStack.empty()){
                prev_op = opStack.top();
                opStack.pop();
                
                b = numStack.top();
                numStack.pop();
                a = numStack.top();
                numStack.pop();
                
                c = cal(a, b, prev_op);
                numStack.push(c);
            }
            
            opStack.push(op);
        }else if(op == '*' || op == '/'){
            prev_op = opStack.top();
            while(!opStack.empty() && (prev_op == '*' || prev_op == '/') ){
                opStack.pop();
                b = numStack.top();
                numStack.pop();
                a = numStack.top();
                numStack.pop();
                
                c = cal(a, b, prev_op);
                numStack.push(c);
                
                if(opStack.empty()){
                    break;
                }
                prev_op = opStack.top();
            }
            
            opStack.push(op);
        }else{
            vector<int> tmpNumStack;
            vector<char> tmpOpStack;
            while(!numStack.empty()){
                tmpNumStack.push_back(numStack.top());
                numStack.pop();
            }
            reverse(tmpNumStack.begin(), tmpNumStack.end());
            
            while(!opStack.empty()){
                tmpOpStack.push_back(opStack.top());
                opStack.pop();
            }
            reverse(tmpOpStack.begin(), tmpOpStack.end());
            
            int ans = 0;
            if(tmpOpStack.size() == 1){
                ans = cal(tmpNumStack[0], tmpNumStack[1], tmpOpStack[0]);
                
            } else if(tmpOpStack.size() > 1) {
                if(tmpOpStack[1] == '*' || tmpOpStack[1] == '/') {
                    ans = cal(tmpNumStack[0], cal(tmpNumStack[1], tmpNumStack[2], tmpOpStack[1]), tmpOpStack[0]);
                } else {
                    ans = cal(cal(tmpNumStack[0], tmpNumStack[1], tmpOpStack[0]), tmpNumStack[2], tmpOpStack[1]);
                }
                
            } else {
                ans = tmpNumStack[0];
            }
            
            numStack.push(ans);
        }
    }
    
    int cal(int a, int b, char op){
        int res = 0;
        switch(op){
            case '+':res = a + b;break;
            case '-':res = a - b;break;
            case '*':res = a * b;break;
            case '/':res = a / b;break;
        }
        return res;
    }
};
