/*
*
* Tag: Hash
* Time: O(nm)
* Space: O(n)
*/
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int ans = 0;
        if(picture.size() == 0){
            return ans;
        }
        
        int n = picture.size(), m = picture[0].size();
        vector<int> rb_cnt(n, 0), cb_cnt(m, 0);
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(picture[i][j] == 'B'){
                    ++ rb_cnt[i];
                    ++ cb_cnt[j];
                }
            }
        }
        
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(picture[i][j] == 'B' && rb_cnt[i] == 1 && cb_cnt[j] == 1){
                    ++ ans;
                }
            }
        }
        
        return ans;
    }
};
