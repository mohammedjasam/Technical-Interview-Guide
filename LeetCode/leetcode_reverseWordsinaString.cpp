/*
* Algorithm: Brute force, Simulate
* Time Complexity: O(n)
* Space Complexity: O(n)
*
*/
class Solution {
public:
    void reverseWords(string &s) {
        int left = 0, right = 0;
        stack<string> ans;
        if(s.size() == 0)
            return ;
        while(!ans.empty())
            ans.pop();
        right = s.size() - 1;
        while(s[left] == ' ') left ++;
        while(s[right] == ' ') right --;
        for(int i = left; i <= right; i ++){
            if(s[i] != ' '){
                string tmp = "";
                while(s[i] != ' ' && i <= right){
                    tmp += s[i];
                    i ++;
                }
                ans.push(tmp);
            }
        }
        bool first = true;
        s = "";
        while(!ans.empty()){
            if(!first)
                s += " ";
            s += ans.top();
            ans.pop();
            first = false;
        }
    }
};

