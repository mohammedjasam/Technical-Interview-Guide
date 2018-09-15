/*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    int addDigits(int num) {
        return num%9 == 0?(num == 0?0:9):num%9;
    }
};
