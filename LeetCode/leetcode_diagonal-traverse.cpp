/*
*
* Tag: Implementation
* Time: O(n*m)
* Space: O(1)
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0)
            return ans;
        int n = matrix.size(), m = matrix[0].size();
        ans.resize(n*m);
        pair<int,int> idx(0,0), nxt;
        bool isDiag = false;
        for(int i = 0; i < n*m; ++ i){
            ans[i] = matrix[idx.first][idx.second];
            if(isDiag){
                nxt = make_pair(idx.first + 1, idx.second - 1);
                if(nxt.first >= n){
                    isDiag = false;
                    nxt = make_pair(n - 1, idx.second + 1);
                    if(nxt.second < 0)
                        nxt = make_pair(n - 1, 1);
                }else if(nxt.second < 0){
                    isDiag = false;
                    nxt = make_pair(idx.first + 1, 0);
                }
            }else{
                nxt = make_pair(idx.first - 1, idx.second + 1);
                if(nxt.first < 0){
                    isDiag = true;
                    nxt = make_pair(0, idx.second + 1);
                    if(nxt.second >= m)
                        nxt = make_pair(1, m - 1);
                }else if(nxt.second >= m){
                    isDiag = true;
                    nxt = make_pair(idx.first + 1, m - 1);
                }
            }
            idx = nxt;
        }
        return ans;
    }
};
