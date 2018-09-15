/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param lower: Integer : lower bound
     * @param upper: Integer : upper bound
     * @return: a list of every possible Digit Divide Numbers
     */
    vector<int> digitDivideNums(int lower, int upper) {
        vector<int> ans;
        if(lower > upper)
            return ans;
        for(int i = lower; isNumInRange(i, lower, upper); ++ i){
            if(isDigitDivideNum(i))
                ans.push_back(i);
        }
        return ans;
    }
private:
    bool isDigitDivideNum(int num){
        int tmpVal = num;
        while(tmpVal > 0){
            int curDigit = tmpVal%10;
            if(curDigit == 0 || num%curDigit != 0)
                return false;
            tmpVal /= 10;
        }
        return true;
    }
    
    bool isNumInRange(int num, int lower, int upper){
        return num >= lower && num <= upper;
    }
};
