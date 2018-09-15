/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        if(!s.size())
            return true;
        int pre = 0, tail = s.size() - 1;
        while(pre < tail){
            int cmppre = -1, cmptail = -1;
            while(pre < tail && !((s[pre] >= 'A' && s[pre] <= 'Z') || (s[pre] >= 'a' && s[pre] <= 'z') || (s[pre] >= '0' && s[pre] <= '9')))
                ++ pre;
            if(pre >=  tail)
                break;
            if((s[pre] >= 'A' && s[pre] <= 'Z') || (s[pre] >= 'a' && s[pre] <= 'z') || (s[pre] >= '0' && s[pre] <= '9')){
                if(s[pre] >= 'A' && s[pre] <= 'Z')
                    cmppre = s[pre] - 'A';
                else if(s[pre] >= 'a' && s[pre] <= 'z')
                    cmppre = s[pre] - 'a';
                else
                    cmppre = (s[pre] - '0') + 100;
            }
            while(pre < tail && !((s[tail] >= 'A' && s[tail] <= 'Z') || (s[tail] >= 'a' && s[tail] <= 'z') || (s[tail] >= '0' && s[tail] <= '9')))
                -- tail;
            if(pre >=  tail)
                break;
            if((s[tail] >= 'A' && s[tail] <= 'Z') || (s[tail] >= 'a' && s[tail] <= 'z') || (s[tail] >= '0' && s[tail] <= '9')){
                if(s[tail] >= 'A' && s[tail] <= 'Z')
                    cmptail = s[tail] - 'A';
                else if(s[tail] >= 'a' && s[tail] <= 'z')
                    cmptail = s[tail] - 'a';
                else
                    cmptail = (s[tail] - '0') + 100;
            }
            if(cmppre != -1 && cmptail != -1){
                if(cmppre != cmptail)
                    return false;
            }
            ++ pre;
            -- tail;
        }
        return true;
    }
};
