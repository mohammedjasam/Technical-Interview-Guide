/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(lgn)
*/
class Solution {
public:
    /**
     * @param alphabet: the new alphabet
     * @param words: the original string array
     * @return: the string array after sorting
     */
    vector<string> wordSort(string &alphabet, vector<string> &words) {
        if(words.size() == 0)
            return words;
        
        vector<int> convertDict(26);
        initConvertDict(convertDict, alphabet);
        
        vector<string> ans(words);
        convert(ans, convertDict);
        
        sort(ans.begin(), ans.end());
        
        revert(ans, alphabet);
        
        return ans;
    }
private:
    void initConvertDict(vector<int> &convertDict, string &alphabet){
        for(int i = 0; i < alphabet.size(); ++ i){
            int key = (alphabet[i] - 'a'), value = i;
            convertDict[key] = value;
        }
    }
    
    void convert(vector<string> &words, vector<int> &convertDict){
        for(int i = 0; i < words.size(); ++ i){
            for(int j = 0; j < words[i].size(); ++ j){
                int key = (words[i][j] - 'a');
                char value = ('a' + convertDict[key]);
                words[i][j] = value;
            }
        }
    }
    
    void revert(vector<string> &words, string &alphabet){
        for(int i = 0; i < words.size(); ++ i){
            for(int j = 0; j < words[i].size(); ++ j){
                int key = (words[i][j] - 'a');
                char value = alphabet[key];
                words[i][j] = value;
            }
        }
    }
};
