/*
*
* Tag: Boggle Game
* Time: O((nm)^2)
* Space: O(26^n)
*/

#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <cmath>
#include <ctype.h>
#include <climits>
#include <utility>
#include <assert.h>
using namespace std;

class TrieNode {
public:
    char content;
    bool isEnd;
    unordered_map<char, TrieNode* > children;
    
    TrieNode(char _content = 0, bool _isEnd = false) {
        children.clear();
        
        content = _content;
        isEnd = _isEnd;
    }
};

class Trie {
public:
    TrieNode *root;
    
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string word){
        if(word.size() == 0){
            return ;
        }
        
        TrieNode *node = root;
        for(char letter : word){
            if(node->children.count(letter) == 0){
                //cout<<letter<<" ";
                node->children[letter] = new TrieNode(letter, false);
            }
            
            node = node->children[letter];
        }
        
        node->isEnd = true;
        //cout<<endl;
    }
};

class boggleGame {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    vector<string> findMostWords(vector<string> words, vector<vector<char>> board){
        vector<string> ans;
        if(words.size() == 0 || board.size() == 0){
            return ans;
        }
        
        Trie trie;
        for(string word : words){
            trie.insert( word );
        }
        
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(trie.root->children.count(board[i][j]) != 0) {
                    //cout<<"start: "<<board[i][j]<<" "<<i<<" "<<j<<endl;
                    vis[i][j] = true;
                    vector<string> tmpans;
                    
                    string str = "";
                    str += board[i][j];
                    //cout<<str<<endl;
                    dfs(ans, tmpans, trie.root, trie.root->children[board[i][j]], str, vis, board, i, j);
                    
                    vis[i][j] = false;
                }
            }
        }
        
        return ans;
    }
    
private:
    void dfs(vector<string> &ans, vector<string> &tmpans, TrieNode *root, TrieNode *node, string str, vector<vector<bool>> &vis, vector<vector<char>> &board, int r, int c){
        if(node->isEnd) {
            //cout<<"find: "<<str<<endl;
            tmpans.push_back(str);
            
            if(tmpans.size() > ans.size()) {
                ans.clear();
                
                ans.insert(ans.end(), tmpans.begin(), tmpans.end());
            }
            
            if(node->children.size() == 0){
                str = "";
                node = root;
            }
        }
        
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < 4; ++ i){
            int nextR = r + dir[i][0], nextC = c + dir[i][1];
            if(nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && !vis[nextR][nextC] && node->children.count(board[nextR][nextC]) != 0 ) {
                
                //cout<<"dfs: "<<board[nextR][nextC]<<" "<<nextR<<" "<<nextC<<endl;
                
                vis[nextR][nextC] = true;
                
                dfs(ans, tmpans, root, node->children[board[nextR][nextC]], str + board[nextR][nextC], vis, board, nextR, nextC);
                
                vis[nextR][nextC] = false;
            }
        }
    }
};

int main() {
    boggleGame bg;
    vector<string> words1 = {"a","b","bc","d","ae","ef"};
    vector<vector<char>> board1 = {{'b','c'},{'e','a'},{'e','f'}};
    vector<string> ans1 = bg.findMostWords(words1, board1);
    cout<<ans1.size()<<endl;
    for(string ans : ans1){
        cout<<ans<<endl;
    }
    cout<<endl;
    
    return 0;
}
