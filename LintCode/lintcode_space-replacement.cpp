/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        if(!length)
            return 0;
        int len = 0;
        for(int i = 0; i < length; ++ i){
            if(string[i] == ' ')
                len += 3;
            else
                ++ len;
        }
        
        int id = len - 1;
        for(int i = length - 1; i >= 0; -- i){
            if(string[i] == ' '){
                string[id--] = '0';
                string[id--] = '2';
                string[id--] = '%';
            }else
                string[id--] = string[i];
        }
        return len;
    }
};  

