/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param tuple: the tuple string
     * @param n: an integer
     * @return: the product of all the nth element in each array
     */
    long long tupleMultiply(string &tuple, int n) {
        long long ans = 1;
        
        for(int idx = 0; idx < tuple.size(); idx += 2) {
            int nextIdx = tuple.find(')', idx);
            ans *= getNthELementFromTuple(tuple, idx, nextIdx, n);
            idx = nextIdx;
        }
        
        return ans;
    }
    
private:
    long long getNthELementFromTuple(string &tuple, int startIdx, int endIdx, int n){
        int numIdx = 0;
        for(int i = startIdx; i < endIdx; ++ i){
            if( (tuple[i] < '0' || tuple[i] > '9') && tuple[i] != '-')
                continue;
            ++ numIdx;
            long long curNum = 0;
            bool isNeg = false;
            if(tuple[i] == '-'){
                isNeg = true;
                ++ i;
            }
            
            while(tuple[i] >= '0' && tuple[i] <= '9'){
                curNum *= 10;
                curNum += (tuple[i] - '0');
                ++ i;
            }
            if(numIdx == n)
                return isNeg? -curNum : curNum;
        }
        return 1;
    }
};
