/*
*
* Tag: BFS
* Time: O(m) where m is the size of dictionary
* Space: O(m)
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.size() != endWord.size()){
            return 0;
        }
        if(beginWord.empty() || endWord.empty()){
            return 1;
        }
        
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(wordList.size() == 0){
            return 0;
        }
        
        queue<pair<string,int>> q;
        q.push(make_pair(beginWord, 1));
        while(dict.size() > 0 && !q.empty()){
            pair<string,int> cur = q.front();
            q.pop();
            string str = cur.first;
            for(int i = 0; i < str.size(); i ++){
                for(int j = 'a'; j <= 'z'; j ++){
                    if(j == str[i])
                        continue;
                    
                    char tmp = str[i];
                    str[i] = j;
                    if(str == endWord)
                        return cur.second + 1;
                    
                    if(dict.find(str) != dict.end()){
                        q.push(make_pair(str, cur.second + 1));
                        dict.erase(str);
                    }
                    str[i] = tmp;
                }
            }
        }
        
        return 0;
    }
};
