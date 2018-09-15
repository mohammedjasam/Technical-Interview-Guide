/*
*
* Tag: Math & Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long long v = stoll(n), x = 1, res = 0;
        for(int i = 62; i >= 1; -- i){
            if((x<<i) < v){
                res = findBase(v, i);
                if(res != 0)
                    return to_string(res);
            }
        }
        return to_string(v-1);
    }
    
private:
    unsigned long long findBase(unsigned long long v, int d){
        unsigned long long l = 2, r = (unsigned long long)pow((double)v, 1.0/d) + 1, mid = 0;
        unsigned long long sum = 0;
        while(l <= r){
            mid = l + ((r - l)>>1);
            sum = cal(mid, d);
            if(sum == v){
                return mid;
            }else if(sum < v){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return 0;
    }
    
    inline unsigned long long cal(unsigned long long v, int d){
        unsigned long long sum = 1, mul = 1;
        for(int i = 1; i <= d; ++ i){
            mul *= v;
            sum += mul;
        }
        return sum;
    }
};
