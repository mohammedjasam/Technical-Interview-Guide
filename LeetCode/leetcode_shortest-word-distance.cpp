/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> wd_one_idx, wd_two_idx;
        int cnt_wd_one = 0, cnt_wd_two = 0;
        for(int i = 0; i < words.size(); ++ i){
            if(words[i] == word1)
                ++ cnt_wd_one;
            if(words[i] == word2)
                ++ cnt_wd_two;
        }
        wd_one_idx.resize(cnt_wd_one);
        cnt_wd_one = 0;
        wd_two_idx.resize(cnt_wd_two);
        cnt_wd_two = 0;
        for(int i = 0; i < words.size(); ++ i){
            if(words[i] == word1)
                wd_one_idx[cnt_wd_one ++] = i;
            if(words[i] == word2)
                wd_two_idx[cnt_wd_two ++] = i;
        }
        int ans = INT_MAX;
        int idx_one = 0, idx_two = 0;
        while(idx_one < cnt_wd_one && idx_two < cnt_wd_two){
            ans = min(ans, abs(wd_one_idx[idx_one] - wd_two_idx[idx_two]));
            if(wd_one_idx[idx_one] < wd_two_idx[idx_two]){
                ++ idx_one;
            }else{
                ++ idx_two;
            }
        }
        return ans;
    }
};
