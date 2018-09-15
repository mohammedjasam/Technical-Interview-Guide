/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
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

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
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

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); ++ i){
            if(node->branches.find(word[i]) != node->branches.end()){
                node = node->branches[word[i]];
            }else
                return false;
        }
        return node->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(int i = 0; i < prefix.size(); ++ i){
            if(node->branches.find(prefix[i]) != node->branches.end()){
                node = node->branches[prefix[i]];
            }else
                return false;
        }
        return true;
    }

private:
    TrieNode* root;
};
