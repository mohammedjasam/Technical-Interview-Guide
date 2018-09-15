/*
*
* Tag: Union Find
* Time: O(n)
* Space: O(n)
*/
class Solution {
private:
    unordered_map<string, int> indexOfWords;
    vector<int> parentIndexInUnionSetOfWordIndex;
    
public:
    Solution(){
        indexOfWords.clear();
    }
    
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size()){
            return false;
        }
        
        initUnionSet( pairs );
        
        buildUnionSet( pairs );
        
        for(int i = 0; i < words1.size(); ++ i){
            if(words1[i] == words2[i]){
                continue;
            }
            
            if(indexOfWords.count(words1[i]) == 0 || indexOfWords.count(words2[i]) == 0){
                return false;
            }
            
            int indexOfWord1 = indexOfWords[words1[i]], indexOfWord2 = indexOfWords[words2[i]];
            if( findParentIndexOfWord( indexOfWord1 ) != findParentIndexOfWord( indexOfWord2 ) ) {
                return false;
            }
        }
        
        return true;
    }
private:
    void initUnionSet(vector<pair<string, string>> &wordPairs){
        indexOfWords.clear();
        
        int currentIndex = 0;
        for(pair<string, string> wordPair : wordPairs ) {
            if(indexOfWords.count(wordPair.first) == 0){
                indexOfWords[wordPair.first] = currentIndex ++;
            }
            if(indexOfWords.count(wordPair.second) == 0){
                indexOfWords[wordPair.second] = currentIndex ++;
            }
        }
        
        parentIndexInUnionSetOfWordIndex.resize(currentIndex);
        for(int i = 0; i < currentIndex; ++ i){
            parentIndexInUnionSetOfWordIndex[i] = -1;
        }
    }
    
    void buildUnionSet(vector<pair<string, string>> &pairs){
        for(pair<string,string> pair : pairs){
            int parentIndexOfWord1 = findParentIndexOfWord(indexOfWords[pair.first]);
            int parentIndexOfWord2 = findParentIndexOfWord(indexOfWords[pair.second]);
            
            int unionSetIndex = parentIndexInUnionSetOfWordIndex[parentIndexOfWord1] + parentIndexInUnionSetOfWordIndex[parentIndexOfWord2];
            if(parentIndexInUnionSetOfWordIndex[parentIndexOfWord1] <= parentIndexInUnionSetOfWordIndex[parentIndexOfWord2]){
                parentIndexInUnionSetOfWordIndex[parentIndexOfWord2] = parentIndexOfWord1;
                parentIndexInUnionSetOfWordIndex[parentIndexOfWord1] = unionSetIndex;
            } else {
                parentIndexInUnionSetOfWordIndex[parentIndexOfWord1] = parentIndexOfWord2;
                parentIndexInUnionSetOfWordIndex[parentIndexOfWord2] = unionSetIndex;
            }
        }
    }
    
    int findParentIndexOfWord(int indexOfWord){
        int currentParentIndexOfWord = indexOfWord;
        
        for(; parentIndexInUnionSetOfWordIndex[currentParentIndexOfWord] >= 0;  currentParentIndexOfWord = parentIndexInUnionSetOfWordIndex[currentParentIndexOfWord]) ;
        
        while(currentParentIndexOfWord != indexOfWord){
            int nextIndexOfWordToUpdate = parentIndexInUnionSetOfWordIndex[indexOfWord];
            parentIndexInUnionSetOfWordIndex[indexOfWord] = currentParentIndexOfWord;
            indexOfWord = nextIndexOfWordToUpdate;
        }
        
        return currentParentIndexOfWord;
    }
};
