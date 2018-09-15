/*
*
* Tag: string
* Time: O(nm) n is the number of words in the list and m is the max length of word
* Space: O(m)
*/
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        if(S.size() == 0){
            return 0;
        }
        
        pair<string,vector<int>> stateOfS = serializeString(S);
        
        int ans = 0;
        for(string word : words){
            pair<string,vector<int>> stateOfWord = serializeString(word);
            if(isExtendedWord(stateOfWord, stateOfS)){
                ++ ans;
            }
        }
        
        return ans;
    }
    
private:
    pair<string,vector<int>> serializeString(string s){
        vector<int> letterCount;
        string ans = "";
        for(int i = 0; i < s.size(); ++ i){
            int cnt = 1;
            while(i < s.size() && s[i] == s[i + 1]){
                ++ cnt;
                ++ i;
            }
            ans += s[i];
            letterCount.push_back(cnt);
        }
        
        return make_pair(ans, letterCount);
    }
    
    bool isExtendedWord(pair<string,vector<int>> &stateOfWord, pair<string,vector<int>>& stateOfS){
        string word = stateOfWord.first, s = stateOfS.first;
        if(word.size() != s.size()){
            return false;
        }
        
        vector<int> letterCountOfWord = stateOfWord.second, letterCountOfS = stateOfS.second;
        for(int i = 0; i < word.size(); ++ i){
            if(word[i] != s[i] || ( (letterCountOfS[i] > 0 && letterCountOfS[i] < 3 && letterCountOfS[i] != letterCountOfWord[i]) ) || (letterCountOfS[i] >= 3 && letterCountOfS[i] < letterCountOfWord[i]) ){
                return false;
            }
        }
        
        return true;
    }
};
