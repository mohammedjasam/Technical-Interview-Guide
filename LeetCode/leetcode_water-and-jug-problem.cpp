/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(lgn)
*/
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z > x && z > y) return false;
        return z%gcd(x, y) == 0;
    }
private:
    int gcd(int a, int b){
        return b == 0?a:gcd(b, a%b);
    }
};
