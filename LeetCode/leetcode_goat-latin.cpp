/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    string toGoatLatin(string S) {
        string ans = "";
        if(S.size() == 0){
            return ans;
        }
        
        string stringOfA = "a";
        for(int i = 0; i < S.size(); ++ i){
            if(S[i] == ' '){
                ans += S[i];
                continue;
            }
            
            string word = "", originWord = "";
            while(i < S.size() && S[i] != ' '){
                originWord += S[i];
                ++ i;
            }
            
            if(originWord != ""){
                char firstLetter = tolower(originWord[0]);
                if(firstLetter != 'a' && firstLetter != 'e' && firstLetter != 'i' && firstLetter != 'o' && firstLetter != 'u'){
                    word = originWord.substr(1)+originWord[0];
                } else {
                    word = originWord;
                }
                ans += word + "ma" + stringOfA;
                stringOfA += "a";
            }
            
            -- i;
        }
        return ans;
    }
};
