/*
*
* Tag: Trie (Data Structure)
* Time: O(nm*maxlen) n is number of rows of matrix, m is number of columns of matrix and maxlen is the max length of words in the list.
* Space: O(26^maxlen)
*/
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(char c=0, bool end=false) {
        content=c;
        isEnd=end;
    }
    char content;
    bool isEnd;
    map<char, TrieNode*> branches;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* node = root;
        int i;
        for(i = 0;i < s.size(); ++ i) {
            if(node->branches.find(s[i]) != node->branches.end()) { 
                node = node->branches[s[i]];
                if(i == s.size()-1)
                    node->isEnd = true;
            }else
                break;
        }
        for(; i < s.size(); ++ i) {
            TrieNode* tmp = new TrieNode(s[i],i == s.size()-1?true:false);
            node->branches[s[i]] = tmp;
            node=tmp;
        }
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* node = root;
        for(int i = 0; i < key.size(); ++ i) {
            bool found = false;
            if(node->branches.find(key[i]) != node->branches.end()) { 
                node = node->branches[key[i]];
            }else
                return false;
        }
        
        return node->isEnd;
    }

    TrieNode* root;
};

class Solution {
private:
    int dir[4][2] = {{-1, 0,}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if(!board.size() || !words.size()){
            return ans;
        }
        
        Trie dict;
        unordered_set<string> st;
        int maxlen = 0;
        for(int i = 0; i < words.size(); ++ i){
            dict.insert(words[i]);
            maxlen = max(maxlen, (int)words[i].size());
        }
        
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                TrieNode* node = dict.root;
                if(node->branches.find(board[i][j]) != node->branches.end()){
                    node = node->branches[board[i][j]];
                    vis[i][j] = 1;
                    string word = "";
                    word += board[i][j];
                    dfs(node, vis, board, i, j, n, m, maxlen, 1, word, ans, st, dict);
                    vis[i][j] = 0;
                }
            }
        }
        
        return ans;
    }
    
    void dfs(TrieNode* node, vector<vector<bool>> &vis, vector<vector<char>>& board, int st_i, int st_j, int n, int m, int maxlen, int dep, string word, vector<string> &ans, unordered_set<string> &st, Trie &dict){
        if(node->isEnd){
            if(st.find(word) == st.end()){
                ans.push_back(word);
                st.insert(word);
            }
        }
        
        if(dep > maxlen) {
            return ;
        }
        
        for(int i = 0; i < 4; ++ i){
            int nxt_st_i = st_i + dir[i][0], nxt_st_j = st_j + dir[i][1];
            
            if( nxt_st_i >= 0 && nxt_st_i < n && nxt_st_j >= 0 && nxt_st_j < m && !vis[nxt_st_i][nxt_st_j] && node->branches.count(board[nxt_st_i][nxt_st_j]) != 0 ) {
                TrieNode *nxt = node->branches[board[nxt_st_i][nxt_st_j]];
                vis[nxt_st_i][nxt_st_j] = true;
                dfs(nxt, vis, board, nxt_st_i, nxt_st_j, n, m, maxlen, dep + 1, word + board[nxt_st_i][nxt_st_j], ans, st, dict);
                vis[nxt_st_i][nxt_st_j] = false;
            }
        }
        
    }
};
