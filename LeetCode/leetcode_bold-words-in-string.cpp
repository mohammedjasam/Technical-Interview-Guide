/*
*
* Tag: Brute Force
* Time: O(nm) where m is the total length of all key words
* Space: O(n)
*/
class Solution {
private:
    vector<bool> boldLetters;
public:
    string boldWords(vector<string>& words, string S) {
        if(words.size() == 0 || S.size() == 0){
            return S;
        }
        
        boldLetters.resize(S.size());
        fill(boldLetters.begin(), boldLetters.end(), false);
        
        for(string word : words){
            boldAllKeyWordsInS(word, S);
        }
        
        string ans = "";
        bool canStartBolding = false;
        for(int i = 0; i <= S.size(); ++ i){
            if(i < S.size() && boldLetters[i]){
                if(!canStartBolding){
                    canStartBolding = true;
                    ans += "<b>";
                }
            } else {
                if(canStartBolding){
                    canStartBolding = false;
                    ans += "</b>";
                }
            }
            
            if(i < S.size())
                ans += S[i];
        }
        
        return ans;
    }
    
private:
    void boldAllKeyWordsInS(string word, string s){
        int startIndex = 0;
        for(; startIndex < s.size(); ++ startIndex){
            startIndex = s.find(word, startIndex);
            if(startIndex >= s.size()){
                break;
            }
            
            int endIndex = startIndex + word.size();
            for(int i = startIndex; i < endIndex; ++ i){
                boldLetters[i] = true;
            }
        }
    }
};
