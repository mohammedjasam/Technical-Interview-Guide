/*
* Tag: Math
* Time: O(lgn) where n is the given num
* Space: O(1)
*
*/
class Solution {
public
    bool isUgly(int num) {
        if(num <= 0)
            return false;
        if(num <= 6)
            return true;
        for(int i = 0; i < 3; ++ i){
            while(num%div_val[i] == 0)
                num/=div_val[i];
            if(num == 1)
                break;
        }
        return num == 1;
    }
private:
    vector<int> div_val={2,3,5};
};
