/*
*
* Tag: Bit Manipulation
* Time: O(lg(n/m))
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
        if(!divisor || (dividend == INT_MIN && divisor == -1) || (dividend == INT_MAX && divisor == 1))
            return INT_MAX;
        if(dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        long long divend = (long long)dividend, divsor = (long long)divisor;
        if(abs(divend) < abs(divsor))
            return 0;
        bool neg_end = divend<0, neg_sor = divsor < 0;
        if(abs(divend) == abs(divsor))
            return neg_end == neg_sor?1:-1;
        divend = abs(divend);
        divsor = abs(divsor);
        vector<long long> mulans(31);
        int bnd = 0;
        init(mulans, bnd, divend, divsor);
        int ans = 0;
        long long mulsum = 0;
        for(int i = bnd; i >= 0; -- i){
            int tmpans = 0;
            long long tmpsum = 0;
            for(int j = 0; j < i; ++ j){
                if(mulans[j] + mulsum > divend)
                    break;
                tmpans = mul[j];
                tmpsum = mulans[j];
            }
            ans |= tmpans;
            mulsum += tmpsum;
        }
        return neg_end == neg_sor?ans:-ans;
    }
    
    void init(vector<long long> &mulans, int &bnd, long long divend, long long divsor){
        mulans[bnd ++] = divsor;
        for(int i = 1; i < 31; ++ i){
            long long tmpmul = divsor+divsor;
            if(tmpmul > divend)
                break;
            mulans[bnd ++] = tmpmul;
            divsor=divsor+divsor;
        }
    }
    
private:
int mul[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
};
