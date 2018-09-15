/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string ans = "";
        if(paragraph.size() == 0){
            return ans;
        }
        
        unordered_set<string> bannedWordDict(banned.begin(), banned.end());
        unordered_map<string, int> wordCounts;
        string word = "";
        paragraph += ".";
        
        int maximumCount = 0;
        for(char letter : paragraph){
            if(isalpha(letter)){
                word += tolower(letter);
            } else {
                if(word.size() > 0 && bannedWordDict.count(word) == 0){
                    ++ wordCounts[word];
                    
                    if(wordCounts[word] > maximumCount) {
                        maximumCount = wordCounts[word];
                        ans = word;
                    }
                }
                word = "";
            }
        }
        
        return ans;
    }
};
