/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size()){
            return false;
        }
        
        unordered_map<string,unordered_set<string>> wordSimilarityDict;
        for(pair<string,string> wordPair : pairs){
            wordSimilarityDict[wordPair.first].insert(wordPair.second);
            wordSimilarityDict[wordPair.second].insert(wordPair.first);
        }
        
        for(int i = 0; i < words1.size(); ++ i){
            string word1 = words1[i], word2 = words2[i];
            if(word1 == word2){
                continue;
            }
            
            if(wordSimilarityDict.count(word1) == 0 || wordSimilarityDict.count(word2) == 0){
                return false;
            }
            
            if(wordSimilarityDict[word1].count(word2) == 0 && wordSimilarityDict[word2].count(word1) == 0){
                return false;
            }
        }
        
        return true;
    }
};
