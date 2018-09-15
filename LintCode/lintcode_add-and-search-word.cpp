/*
*
* Tag: Data Structure, Trie
* Time: O(26^m) where m is the longest word in dictionary
* Space: O(26^m) where m is the longest word in dictionary
*/
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(char c=0, bool end=false) {
        content = c;
        isEnd = end;
    }
    
    char content;
    bool isEnd;
    unordered_map<char, TrieNode *> branches;
};


class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *node = root;
        int i = 0;
        for(; i < word.size(); ++ i){
            if(node->branches.find(word[i]) != node->branches.end()){
                node = node->branches[word[i]];
                if(i == word.size() - 1)
                    node->isEnd = true;
            }else
                break;
        }
        for(; i < word.size(); ++ i){
            TrieNode *tmp = new TrieNode(word[i], i == word.size() -1);
            node->branches[word[i]] = tmp;
            node = tmp;
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if(word.size() == 0)
            return true;
        queue<TrieNode *> q;
        q.push(root);
        for(int i = 0; i < word.size(); ++ i){
            queue<TrieNode *> tmpq;
            while(!tmpq.empty())
                tmpq.pop();
            bool isfind = false;
            while(!q.empty()){
               TrieNode *node = q.front();
               q.pop();
               if(node->branches.find(word[i]) != node->branches.end()){
                    tmpq.push(node->branches[word[i]]);
                    isfind = true;
                }else if(word[i] == '.'){
                    unordered_map<char, TrieNode *>::iterator it = node->branches.begin();
                    for(; it != node->branches.end(); ++ it){
                        tmpq.push(it->second);
                    }
                    isfind = true;
                }
            }
            if(!isfind)
                return false;
            q = tmpq;
        }
        while(!q.empty()){
            TrieNode *tmp = q.front();
            q.pop();
            if(tmp->isEnd)
                return true;
        }
        return false;
    }
    
private:
    TrieNode* root;
};
