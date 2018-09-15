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
        int ans = 0;
        if(s.size() == 0){
            return ans;
        }
        
        s = "("+s+")";
        for(int i = 0; i < s.size(); ++ i){
            if(s[i] == ' '){
                continue;
            }
            
            if(s[i] == '('){
                opStack.push(s[i]);
            } else if(s[i] >= '0' && s[i] <= '9'){
                int num = 0;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
                    num = num*10 + (s[i] - '0');
                    ++ i;
                }
                -- i;
                
                numStack.push(num);
            } else {
                getOpRes(s[i]);
            }
        }
        
        ans = numStack.top();
        return ans;
    }
    
private:
    void getOpRes(char op){
        int a, b, c;
        char prevOp;
        
        if(op == '+' || op == '-') {
            while(!opStack.empty() && opStack.top() != '('){
                prevOp = opStack.top();
                opStack.pop();
                
                b = numStack.top();
                numStack.pop();
                a = numStack.top();
                numStack.pop();
                c = calCulate(a, b, prevOp);
                
                numStack.push(c);
            }
            
            opStack.push(op);
        } else if(op == '*' || op == '/') {
            while(!opStack.empty() && opStack.top() != '(' && opStack.top() != '+' && opStack.top() != '-'){
                prevOp = opStack.top();
                opStack.pop();
                
                b = numStack.top();
                numStack.pop();
                a = numStack.top();
                numStack.pop();
                c = calCulate(a, b, prevOp);
                
                numStack.push(c);
            }
            
            opStack.push(op);
        } else {
            int numOfOp = 0;
            vector<char> opVec;
            while(!opStack.empty() && opStack.top() != '(') {
                opVec.push_back(opStack.top());
                opStack.pop();
                ++ numOfOp;
            }
            reverse(opVec.begin(), opVec.end());
            
            int numOfNum = numOfOp + 1;
            vector<int> numVec;
            while(!numStack.empty() && numOfNum > 0) {
                numVec.push_back(numStack.top());
                numStack.pop();
                -- numOfNum;
            }
            reverse(numVec.begin(), numVec.end());
            
            if(numOfOp == 0){
                c = numVec[0];
            }else if(numOfOp == 1){
                c = calCulate(numVec[0], numVec[1], opVec[0]);
            } else {
                c = calCulate(numVec[0], calCulate(numVec[1], numVec[2], opVec[1]), opVec[0]);
            }
            
            if(!opStack.empty() && opStack.top() == '('){
                opStack.pop();
            }
            
            numStack.push(c);
        }
    }
    
    int calCulate(int a, int b, char op){
        int ans = 0;
        switch(op){
            case '+': ans = a + b;break;
            case '-': ans = a - b;break;
            case '*': ans = a * b;break;
            case '/': ans = a / b;break;
        }
        
        return ans;
    }
};
