/*
*
* Tag: String
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 0){
            return chars.size();
        }
        
        int ans = 0;
        char lastLetter = 0;
        int countOfCurLetter = 0;
        chars.push_back(0);
        for(char letter : chars){
            if(lastLetter == letter) {
                ++ countOfCurLetter;
            } else {
                if(lastLetter != 0) {
                    chars[ans ++] = lastLetter;
                }
                if(countOfCurLetter > 1){
                    string countOfLetter = to_string(countOfCurLetter);
                    for(char digit : countOfLetter){
                        chars[ans ++] = digit;
                    }
                }
                
                countOfCurLetter = 1;
            }
            
            lastLetter = letter;
        }
        
        chars.resize(ans);
        
        return ans;
    }
};
