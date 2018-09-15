/*
*
* Tag: BFS
* Time: https://leetcode.com/articles/k-similar-strings/
* Space: O(n*Time)
*/
class Solution {
public:
    int kSimilarity(string A, string B) {
        int ans = 0;
        if(A == B){
            return ans;
        }
        
        queue<pair<string, pair<int, int>>> q;
        q.push(make_pair(A, make_pair(0, 0)));
        
        unordered_set<string> visitedState;
        
        ans = -1;
        while(!q.empty()){
            pair<string,pair<int, int>> state = q.front();
            q.pop();
            
            string curStr = state.first;
            pair<int,int> curCheckState = state.second;
            if(curStr == B){
                ans = curCheckState.first;
                break;
            }
            
            int nextUnmatchedIndex = curCheckState.second;
            for(; nextUnmatchedIndex < curStr.size(); ++ nextUnmatchedIndex){
                if(curStr[nextUnmatchedIndex] != B[nextUnmatchedIndex]){
                    break;
                }
            }
            
            if(nextUnmatchedIndex >= curStr.size()){
                ans = curCheckState.first + 1;
                break;
            }
            
            for(int i = nextUnmatchedIndex + 1; i < curStr.size(); ++ i){
                if(curStr[i] != B[nextUnmatchedIndex]){
                    continue;
                }
                
                string nextStr = curStr;
                swap(nextStr[nextUnmatchedIndex], nextStr[i]);
                if(visitedState.count(nextStr) == 0){
                    q.push(make_pair(nextStr, make_pair(curCheckState.first + 1, nextUnmatchedIndex + 1)));
                    visitedState.insert(nextStr);
                }
            }
        }
        
        return ans;
    }
};
