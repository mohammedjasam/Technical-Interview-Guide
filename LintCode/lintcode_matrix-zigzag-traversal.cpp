/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        vector<int> ans;
        if(!matrix.size())
            return ans;
        if(matrix.size() == 1){
            ans.resize(matrix[0].size());
            for(int i = 0; i < matrix[0].size(); ++ i)
                ans[i] = matrix[0][i];
            return ans;
        }
        if(matrix[0].size() == 1){
            ans.resize(matrix.size());
            for(int i = 0; i < matrix.size(); ++ i)
                ans[i] = matrix[i][0];
            return ans;
        }
        int n = matrix.size(), m = matrix[0].size();
        ans.resize(n*m);
        int state = 0, cnt = 0, i = 0, j = 0;
        ans[cnt ++] = matrix[0][0];
        for(; cnt < n*m; ){
            if(!state){
                if(i < n && j + 1 < m){
                    ++ j;
                    ans[cnt ++] = matrix[i][j];
                    state = (state + 1)%4;
                }else if(i + 1 < n && j < m){
                    ++ i;
                    ans[cnt ++] = matrix[i][j];
                    state = (state + 1)%4;
                }
            }else if(state == 1){
                if(i + 1< n && j - 1 >= 0){
                    ++ i;
                    -- j;
                    ans[cnt ++] = matrix[i][j];
                }else
                    state = (state + 1)%4;
            }else if(state == 2){
                if(i + 1 < n && j >= 0){
                    ++ i;
                    ans[cnt ++] = matrix[i][j];
                    state = (state + 1)%4;
                }else if(i < n && j + 1 < m){
                    ++ j;
                    ans[cnt ++] = matrix[i][j];
                    state = (state + 1)%4;
                }
            }else{
                if(i - 1 >= 0 && j + 1 < m){
                    -- i;
                    ++ j;
                    ans[cnt ++] = matrix[i][j];
                }else
                    state = (state + 1)%4;
            }
        }
        return ans;
    }
};
