/*
*
* Tag: Binary Search
* Time: O(m*lg(n)) m is the total length of words and n is the length of string S.
* Space: O(n)
*/
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        if(S.size() == 0 || words.size() == 0){
            return 0;
        }
        
        vector<vector<int>> letterIndexDict(26, vector<int>());
        for(int i = 0; i < S.size(); ++ i){
            letterIndexDict[S[i] - 'a'].push_back(i);
        }
        
        int ans = 0;
        for(string word : words){
            int curIndex = -1;
            bool isFound = true;
            
            for(char letter : word){
                auto it = upper_bound(letterIndexDict[letter - 'a'].begin(), letterIndexDict[letter - 'a'].end(), curIndex);
                if(it == letterIndexDict[letter - 'a'].end()) {
                    isFound = false;
                    break;
                }
                curIndex = *it;
            }
            
            if(isFound){
                ++ ans;
            }
            
        }
        
        return ans;
    }
};
