/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        if(S == T){
            return true;
        }
        
        int indexOfS = S.size() - 1, indexOfT = T.size() - 1;
        for(; indexOfS >= 0 && indexOfT >= 0; -- indexOfS, -- indexOfT){
            if(S[indexOfS] == '#'){
                indexOfS = getActualTextIndexOfString(indexOfS, S);
            }
            
            if(T[indexOfT] == '#'){
                indexOfT = getActualTextIndexOfString(indexOfT, T);
            }
            
            if(indexOfS < 0 && indexOfT < 0){
                break;
            } else if(indexOfS >= 0 && indexOfT < 0){
                return false;
            } else if(indexOfS < 0 && indexOfT >= 0){
                return false;
            } else if(S[indexOfS] != T[indexOfT]) {
                return false;
            }
        }
                
        return getActualTextIndexOfString(indexOfS, S) < 0 && getActualTextIndexOfString(indexOfT, T) < 0;
    }
private:
    int getActualTextIndexOfString(int startIndex, string s){
        if(startIndex < 0){
            return -1;
        }
        
        if(s[startIndex] != '#'){
            return startIndex;
        }
        
        int ansIndex = startIndex - 1;
        int countOfBackSpace = 1;
        
        while(ansIndex >= 0 && countOfBackSpace > 0){
            if(s[ansIndex] == '#'){
                ++ countOfBackSpace;
            } else {
                -- countOfBackSpace;
            }
            
            -- ansIndex;
            if(ansIndex >= 0 && countOfBackSpace == 0 && s[ansIndex] == '#'){
                countOfBackSpace = 1;
                -- ansIndex;
            }
        }
        
        return ansIndex;
    }
};
