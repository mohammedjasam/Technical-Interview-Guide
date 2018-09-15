/*
*
* Tag: String
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /*
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    bool isPalindrome(int num) {
        string str_num = to_string(num);
        return str_num == string(str_num.rbegin(), str_num.rend());
    }

};
