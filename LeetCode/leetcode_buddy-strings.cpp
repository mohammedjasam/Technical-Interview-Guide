/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()){
            return false;
        }
        
        if(A == B && hasDuplicatedLetters(A)){
            return true;
        }
        
        pair<int,int> indexesOfTwoDifferentChars(-1, -1);
        int numOfDifference = 0;
        for(int i = 0; i < A.size(); ++ i){
            if(A[i] != B[i]){
                ++ numOfDifference;
                
                if(indexesOfTwoDifferentChars.first == -1){
                    indexesOfTwoDifferentChars.first = i;
                } else {
                    indexesOfTwoDifferentChars.second = i;
                }
            }
            
            if(numOfDifference > 2){
                break;
            }
        }
        
        return numOfDifference == 2 && A[indexesOfTwoDifferentChars.first] == B[indexesOfTwoDifferentChars.second] && A[indexesOfTwoDifferentChars.second] == B[indexesOfTwoDifferentChars.first];
    }
    
private:
    bool hasDuplicatedLetters(string s){
        vector<bool> visitedLetter(26, false);
        
        for(char letter : s){
            int key = letter - 'a';
            if(visitedLetter[key]){
                return true;
            }
            
            visitedLetter[key] = true;
        }
        
        return false;
    }
};
