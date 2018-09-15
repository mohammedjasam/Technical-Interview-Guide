/*
*
* Tag: Topological Sort
* Time: O(nm)
* Space: O(1)
*/
class Solution {
private:
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> deg;
    
public:
    string alienOrder(vector<string>& words) {
        string ans = "";
        if(words.size() == 0){
            return ans;
        }
        
        buildGraph(words);
        
        queue<char> q;
        unordered_set<char> visitedLetters;
        for(pair<char,int> letterOfDeg : deg){
            if(letterOfDeg.second == 0){
                q.push(letterOfDeg.first);
                visitedLetters.insert(letterOfDeg.first);
            }
        }
        
        while(!q.empty()){
            char curLetter = q.front();
            q.pop();
            
            for(char nextLetter : graph[curLetter]){
                -- deg[nextLetter];
                if(deg[nextLetter] == 0 && visitedLetters.count(nextLetter) == 0){
                    visitedLetters.insert(nextLetter);
                    q.push(nextLetter);
                }
            }
            
            ans += curLetter;
        }
        
        return visitedLetters.size() == deg.size() ? ans : "";
    }
    
private:
    void buildGraph(vector<string>& words){
        graph.clear();
        deg.clear();
        
        for(string word : words){
            for(char letter : word){
                deg[letter] = 0;
            }
        }
        
        for(int i = 0; i < words.size() - 1; ++ i){
            string word1 = words[i], word2 = words[i + 1];
            int indexOfWord1 = 0, indexOfWord2 = 0;
            
            while(indexOfWord1 < word1.size() && indexOfWord2 < word2.size()){
                char u = word1[indexOfWord1], v = word2[indexOfWord2];
                if(u != v){
                    if(graph.count(u) == 0 || graph[u].count(v) == 0){
                        graph[u].insert(v);
                        ++ deg[v];
                    }
                    
                    break;
                }
                
                ++ indexOfWord1;
                ++ indexOfWord2;
            }
        }
    }
};
