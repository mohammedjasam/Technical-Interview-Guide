/*
*
* Tag: Greedy + Stack
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        if(s.size() == 0){
            return ans;
        }
        
        unordered_map<char,int> letterCount;
        for(char letter : s){
            ++ letterCount[letter];
        }
        
        vector<char> stack(30);
        int top = 0;
        vector<bool> visitedLetter(30, false);
        for(int i = 0; i < s.size(); -- letterCount[s[i]], ++ i){
            int key = s[i] - 'a';
            if(visitedLetter[key] || (top > 0 && stack[top - 1] == s[i])) {
                continue;
            }
            
            while(top > 0 && stack[top - 1] > s[i] && letterCount[stack[top - 1]] > 0){
                visitedLetter[stack[top - 1] - 'a'] = false;
                -- top;
            }
            visitedLetter[key] = true;
            stack[top ++] = s[i];
        }
        
        for(int i = 0; i < top; ++ i){
            ans += stack[i];
        }
        return ans;
    }
};
