/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    string replaceWords(vector<string>& _dict, string sentence) {
        string ans = "";
        if(sentence.size() == 0 || _dict.size() == 0){
            return ans;
        }
        
        unordered_set<string> dict(_dict.begin(), _dict.end());
        
        string curWord = "";
        for(int i = 0; i < sentence.size(); ++ i){
            char letter = sentence[i];
            if(isalpha(letter)) {
                curWord += letter;
                if(dict.count(curWord)) {
                    ans += curWord;
                    
                    while(i < sentence.size() && isalpha(letter)){
                        ++ i;
                        letter = sentence[i];
                    }
                    -- i;
                    
                    curWord = "";
                    
                } else if(letter == ' ' ||i == sentence.size() - 1){
                    ans += curWord;
                    curWord = "";
                }
            } else {
                if(curWord.size() > 0) {
                    ans += curWord;
                }
                
                ans += letter;
                curWord = "";
            }
        }
        
        return ans;
    }
};
