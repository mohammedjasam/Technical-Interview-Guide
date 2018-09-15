/*
*
* Tag: String
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        bool star = false;
        const char *str, *ptr;
        for(str = s, ptr = p; *str; str ++, ptr ++){
            switch(*ptr){
                case '?':break;
                case '*':
                    star = true;
                    s = str, p = ptr;
                    while(*p == '*') 
                        p ++;
                    if(*p == '\0')
                        return true;
                    str = s - 1;
                    ptr = p - 1;
                    break;
                default:
                    if(*str != *ptr){
                        if(!star)
                            return false;
                        s ++;
                        str = s - 1;
                        ptr = p - 1;
                    }
            }
        }
        while(*ptr == '*') ptr ++;
        return *ptr == '\0';
    }
};
