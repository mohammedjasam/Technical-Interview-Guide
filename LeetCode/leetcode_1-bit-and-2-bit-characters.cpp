/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        return isValidOneBitLastCharacter(bits, 0);
    }
    
private:
    bool isValidOneBitLastCharacter(vector<int>& bits, int startIndex){
        int actualBitsSize = bits.size() - startIndex;
        if(actualBitsSize <= 0){
            return false;
        }
        
        if(actualBitsSize == 1){
            return bits[startIndex] == 0;
        }
        
        return bits[startIndex] == 0 ? isValidOneBitLastCharacter(bits, startIndex + 1) : isValidOneBitLastCharacter(bits, startIndex + 2);
    }
};
