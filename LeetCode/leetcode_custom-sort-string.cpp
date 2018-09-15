/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    string customSortString(string S, string T) {
        if(S.size() == 0){
            return T;
        }
        
        vector<int> countOfLetters(26, 0);
        for(char letter: T){
            int index = (int)(letter - 'a');
            ++ countOfLetters[index];
        }
        
        string ans = "";
        for(char letter : S){
            int index = (int)(letter - 'a');
            while(countOfLetters[index] > 0){
                ans += letter;
                -- countOfLetters[index];
            }
        }
        
        for(int i = 0; i < 26; ++ i){
            while(countOfLetters[i] > 0){
                ans += (char)('a' + i);
                -- countOfLetters[i];
            }
        }
        
        return ans;
    }
};
