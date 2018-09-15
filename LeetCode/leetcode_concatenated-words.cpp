/*
*
* Tag: DP + Data Structure or DFS + Data Structure
* Time: O(n^2)
* Space: O(nm) where m is the average length of given words
*/
class TrieNode {
public:
    char content;
    bool isEnd;
    unordered_map<char, TrieNode *> branches;
    
    TrieNode(char c=0, bool end=false){
        content = c;
        isEnd = end;
    }
};

class Trie{
private:
    TrieNode *root;
public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string s){
        TrieNode *node = root;
        int i;
        for(i = 0; i < s.size(); ++ i){
            if(node->branches.find(s[i]) != node->branches.end()){
                node = node->branches[s[i]];
                if(i == s.size() - 1)
                    node->isEnd = true;
            }else
                break;
        }
        for(; i < s.size(); ++ i){
            TrieNode *tmp = new TrieNode(s[i], i == s.size()-1?true:false);
            node->branches[s[i]] = tmp;
            node = tmp;
        }
    }
    
    void search(string &s, int start, vector<int> &dp){
        TrieNode *node = root;
        for(int i = start; i < s.size(); ++ i){
            if(node->branches.find(s[i]) != node->branches.end()){
                node = node->branches[s[i]];
                if(node->isEnd){
                    dp[i] = (start == 0? 1 : max(dp[i], dp[start - 1] + 1));
                }
            }else
                break;
        }
    }
};

class Solution {
//private:
private:
    struct cmpfun{
        bool operator() (const string a, const string b){
            return a.size() < b.size();
        }
    }cmp;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        if(words.size() == 0)
            return ans;
        sort(words.begin(), words.end(), cmp);
        Trie tree;
        int maxlen = 0;
        for(int i = 0; i < words.size(); ++ i){
            maxlen = max(maxlen, (int)words[i].size());
        }
        vector<int> dp(maxlen + 1);
        for(int i = 0; i < words.size(); ++ i){
            
            for(int j = 0; j < words[i].size(); ++ j)
                dp[j] = 0;
            
            for(int j = 0; j < words[i].size(); ++ j){
                if(j == 0 || dp[j - 1] > 0)
                    tree.search(words[i], j, dp);
                if(dp[words[i].size() - 1] > 1){
                    ans.push_back(words[i]);
                    break;
                }
            }
            if(dp[words[i].size() - 1] < 1)
                tree.insert(words[i]);
        }
        return ans;
    }
};


/*
*
* Tag: DFS + Data Structure
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
private:
    struct cmpfun{
        bool operator() (const string a, const string b){
            return a.size() < b.size();
        }
    }cmp;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        if(words.size() == 0)
            return ans;
        sort(words.begin(), words.end(), cmp);
        unordered_set<string> st;
        string path;
        for(int i = 0; i < words.size(); ++ i){
            path = "";
            if(dfs(words[i], 0, 0, path, st))
                ans.push_back(words[i]);
            else
                st.insert(words[i]);
        }
        return ans;
    }
private:
    bool dfs(string &word, int idx, int cnt, string &path, unordered_set<string> &st){
        if(idx >= word.size()){
            if(st.find(path) != st.end() && cnt > 0)
                return true;
            else
                return false;
        }
        path += word[idx];
        if(st.find(path) != st.end()){
            string tmp = "";
            if(dfs(word, idx + 1, cnt + 1, tmp, st))
                return true;
        }
        if(dfs(word, idx + 1, cnt, path, st))
            return true;
        else
            return false;
    }
};
