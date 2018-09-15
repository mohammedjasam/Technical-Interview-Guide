/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(!num)
            return false;
        if(num == 1)
            return true;
        return findTarget(num);
    }
private:
    bool findTarget(int num){
        int l = 2, r = num - 1;
        while(l <= r){
            long long mid = (l + r)>>1;
            long long val = mid*mid;
            if(val == num)
                return true;
            else if(val < num)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};
