/*
*
* Tag: Hash
* Time: build: O(n), search: O(m) 
* Space: O(n)
*/
class MagicDictionary {
private:
    unordered_set<string> dictionary;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        dictionary.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(string word : dict){
            dictionary.insert(word);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(int i = 0; i < word.size(); ++ i){
            char letter = word[i];
            for(int j = 0; j < 26; ++ j){
                char newLetter = (char)('a' + j);
                if(newLetter == letter){
                    continue;
                }
                
                word[i] = newLetter;
                if(dictionary.count(word) != 0){
                    return true;
                }
            }
            word[i] = letter;
        }
        
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
