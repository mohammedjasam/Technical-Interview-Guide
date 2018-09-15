/*
*
* Tag: Stack (Data Structure)
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int ans = 0;
        if(tokens.size() == 0) {
            return ans;
        }
        
        stack<int> num;
        for(int i = 0; i < tokens.size(); i ++){
            string tmp = tokens[i];
            if(tmp[0] >= '0' && tmp[0] <= '9' || (tmp[0] == '-' && tmp[1] >= '0' && tmp[1] <= '9')){
                string::size_type sz;
                int val = stoi (tmp,&sz);
                num.push(val);
            }else{
                int b = num.top();
                num.pop();
                int a = num.top();
                num.pop();
                int c = cal(a,b,tmp[0]);
                num.push(c);
            }
        }

        return num.top();
    }
    
    int cal(int a, int b, char op){
        int c = 0;
        switch(op) {
            case '+': c = a + b;break;
            case '-': c = a - b;break;
            case '*': c = a * b;break;
            case '/': c = a / b;break;
        }
        
        return c;
    }
};
