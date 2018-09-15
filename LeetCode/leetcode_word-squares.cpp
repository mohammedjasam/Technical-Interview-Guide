/*
*
* Tag: Data Structure + DFS
* Time: O(n!)
* Space: O(m)
*/
class Solution {
private:
    struct TrieNode{
        vector<int> indexs;
        vector<TrieNode *> children;
        TrieNode(){
            children.resize(26, NULL);
        }
    };
public:
    TrieNode *buildTrie(vector<string> &words){
        TrieNode *root = new TrieNode(), *t = NULL;
        for(int i = 0; i < words.size(); ++ i){
            t = root;
            for(int j = 0; j < words[i].size(); ++ j){
                if(t->children[words[i][j] - 'a'] == NULL)
                    t->children[words[i][j] - 'a'] = new TrieNode();
                t = t->children[words[i][j] - 'a'];
                t->indexs.push_back(i);
            }
        }
        return root;
    }
    
    void dfs(vector<string>& words, int dep, TrieNode *root, vector<string> &vec, vector<vector<string>> &res){
        if(dep >= words[0].size()){
            res.push_back(vec);
            return ;
        }
        string s = "";
        TrieNode *t = root;
        for(int i = 0; i < dep; ++ i)
            s += vec[i][dep];
        for(int i = 0; i < s.size(); ++ i){
            if(!(t = t->children[s[i] - 'a']))
                return ;
        }
        for(int i = 0; i < t->indexs.size(); ++ i){
            vec[dep] = words[t->indexs[i]];
            dfs(words, dep + 1, root, vec, res);
        }
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;
        if(words.size() == 0)
            return res;
        vector<string> vec;
        vector<bool> vis;
        TrieNode *root = buildTrie(words);
        vec.resize(words[0].size());
        for(int i = 0; i < words.size(); ++ i){
            vec[0] = words[i];
            dfs(words, 1, root, vec, res);
        }
        return res;
    }
};
