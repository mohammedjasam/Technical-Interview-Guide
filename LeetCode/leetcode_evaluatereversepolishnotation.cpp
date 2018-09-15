/*
* Algorithm: data structure
* Time complexity: O(n)
* Memory complexity: O(n)
*/
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int val = 0;
        if(tokens.size() == 0)
            return val;
        stack<int> num_stak;
        while(!num_stak.empty())
            num_stak.pop();
        for(int i = 0; i < tokens.size(); i ++){
            int tmp_val = 0;
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                tmp_val = getNum(tokens[i]);
                num_stak.push(tmp_val);
            }else{
                int a, b;
                a = num_stak.top();
                num_stak.pop();
                b = num_stak.top();
                num_stak.pop();
                if(tokens[i] == "+")
                    val = b + a;
                else if(tokens[i] == "-")
                    val = b - a;
                else if(tokens[i] == "*")
                    val = b * a;
                else
                    val = b/a;
                num_stak.push(val);
            }
        }
        val = num_stak.top();
        return val;
    }
    
    int getNum(string str){
        bool flag = false;
        int res = 0;
        if(str[0] == '-') 
            flag = true;
        int i = 0;
        if(flag)
            i ++;
        for(; i < str.size(); i ++){
            res = res*10 + (str[i] - '0');
        }
        return flag?-res:res;
    }
};
