/*
*
* Tag: Bit Manipulation
* Time: O(max(O(mn),O(n^2)) where m is the average length of string words
* Space: O(n)
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        if(words.size() < 2) {
            return ans;
        }
        
        int n = words.size();
        vector<int> val(n);
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < words[i].size(); ++ j){
                int k = words[i][j] - 'a';
                val[i] |= (1<<k);
            }
        }
        
        for(int i = 0; i < n - 1; ++ i){
            for(int j = i + 1; j < n; ++ j){
                if((val[i]&val[j]) == 0){
                    ans = max(ans, (int)((int)words[i].size()*(int)words[j].size()));
                }
            }
        }
        
        return ans;
    }
};
