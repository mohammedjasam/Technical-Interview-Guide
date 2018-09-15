/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(n)
*/
class Solution {
private:
    stack<string> strStack;
    stack<int> numStack;
public:
    string decodeString(string s) {
        if(!s.size()) {
            return s;
        }
        
        s = "["+ s +"]";
        strStack.push("");
        numStack.push(1);
        for(int i = 0; i < s.size(); ++ i) {
            if(s[i] == '[') {
                strStack.push("");
                continue;
            }
            
            if(s[i] >= '0' && s[i] <= '9'){
                string num = "";
                while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    num += s[i];
                    ++ i;
                }
                --i;
                
                numStack.push(stoi(num));
            } else if(s[i] == ']') {
                string curStr = strStack.top();
                strStack.pop();
                int strFrequency = numStack.top();
                numStack.pop();
                
                string lastStr = strStack.top();
                strStack.pop();
                appendString(lastStr, curStr, strFrequency);
                strStack.push(lastStr);
            } else {
                string curStr = strStack.top();
                strStack.pop();
                
                curStr += s[i];
                strStack.push(curStr);
            }
        }
        
        return strStack.top();
    }

private:
    void appendString(string &s, string addedS, int frequency) {
        for(int i = 0; i < frequency; ++ i){
            s += addedS;
        }
        
        return ;
    }
};
