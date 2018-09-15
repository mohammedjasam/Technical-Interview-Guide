/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/
class Solution {
private:
    unordered_map<char,int> rotatedDifferentDigitDict{ 
        {'0', 0},
        {'1', 1},
        {'2', 5},
        {'3', -1},
        {'4', -1},
        {'5', 2},
        {'6', 9},
        {'7', -1},
        {'8', 8},
        {'9', 6}
    };
public:
    int rotatedDigits(int N) {
        int ans = 0;
        
        for(int i = 1; i <= N; ++ i){
            if(canRotateToValidDifferentNum(i)){
                ++ ans;
            }
        }
        
        return ans;
    }
    
    bool canRotateToValidDifferentNum(int originalNum){
        string originalNumString = to_string(originalNum), rotatedNumString = "";
        
        for(char digit : originalNumString){
            int rotatedDigit = rotatedDifferentDigitDict[digit];
            if(rotatedDigit == -1){
                return false;
            }
            
            rotatedNumString += (char)(rotatedDigit + '0');
        }
        
        return originalNumString != rotatedNumString;
    }
};
