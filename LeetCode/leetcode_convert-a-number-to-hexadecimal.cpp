/*
*
* Tag: Bit Manipulation
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    string toHex(int num) {
        unsigned int val = (int)num;
        string res = "";
        do{
            res = dict[(val&mask)] + res;
            val >>= 4;
        }while(val);
        return res;
    }
private:
    string dict="0123456789abcdef";
    int mask=15;
};
