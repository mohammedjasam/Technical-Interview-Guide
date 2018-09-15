/*
*
* Tag: DP + Data Structure (Trie)
* Time: O(nml) where l is the length of word list and m is the average length of words in the list.
* Space: O(26^max(m))
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <climits>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
using namespace std;

class TrieNode {
public:
    char content;
    bool isEnd;
    unordered_map<char, TrieNode *> children;
    
    TrieNode(char _content = 0, bool _isEnd = false){
        children.clear();
        content = _content;
        isEnd = _isEnd;
    }
};

class Trie{
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
                TrieNode *newNode = new TrieNode(letter, false);
                node->children[letter] = newNode;
            }
            
            node = node->children[letter];
        }
        
        node->isEnd = true;
    }
};

class EdistanceCalculator {
private:
    int k;
public:
    vector<string> getKEditDistanceWordsOf(vector<string> words, string target, int _k){
        vector<string> ans;
        if(words.size() == 0){
            return ans;
        }
        
        k = _k;
        Trie tree;
        for(string word : words){
            tree.insert(word);
        }
        
        vector<int> dp(target.size() + 1, 0);
        for(int i = 1; i <= target.size(); ++ i){
            dp[i] = i;
        }
        
        searchKEditDistanceWords(tree.root, dp, "", target, ans);
        
        return ans;
    }

private:
    void searchKEditDistanceWords(TrieNode *node, vector<int> &prevDp, string word, string &target, vector<string> &ans){
        if(node->isEnd) {
            if(prevDp[target.size()] <= k){
                ans.push_back(word);
            } else {
                return ;
            }
        }
        
        for(auto it = node->children.begin(); it != node->children.end(); ++ it){
            vector<int> curDp(target.size() + 1, 0);
            curDp[0] = word.size() + 1;
            
            char curLetter = it->first;
            for(int i = 1; i <= target.size(); ++ i){
                if(curLetter == target[i - 1]) {
                    curDp[i] = prevDp[i - 1];
                    continue;
                } 
                
                // prevDp[i - 1]: update curLetter as target[i]; 
                // prevDp[i]: delete curLetter;
                // curDp[i - 1]: append target[i] to the end of word.
                curDp[i] = min(min(prevDp[i - 1], prevDp[i]), curDp[i - 1]) + 1;
            }
            
            searchKEditDistanceWords(it->second, curDp, word + curLetter, target, ans);
        }
        
        return ;
    }
};

int main() {
    EdistanceCalculator edc;
    vector<string> words1 = {"abc","bcd","cde","hui","kdfsef","c"};
    string target = "abc";
    int k = 0;
    vector<string> ans = edc.getKEditDistanceWordsOf(words1, target, k);
    assert( ans.size() == 1 );
    assert( ans[0] == "abc" );
    
    vector<string> words2 = {"abcd", "abc", "abd", "ad", "c", "cc"};
    target = "abcd";
    k = 2;
    ans = edc.getKEditDistanceWordsOf(words2, target, k);
    assert( ans.size() == 4 );
    sort(ans.begin(), ans.end());
    assert( ans[0] == "abc" );
    assert( ans[1] == "abcd" );
    assert( ans[2] == "abd" );
    assert( ans[3] == "ad" );
    return 0;
}
