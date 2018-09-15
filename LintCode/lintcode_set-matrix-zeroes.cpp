/*
*
* Tag: Brute Force
* Time: O(n^2)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        // write your code here
        if(matrix.size() == 0)
            return ;
        int n = matrix.size(), m = matrix[0].size();
        bool row_one_zero = false, column_one_zero = false;
        for(int i = 0; i < m; ++ i){
            if(matrix[0][i] == 0){
                row_one_zero = true;
                break;
            }
        }
        for(int i = 0; i < n; ++ i){
            if(matrix[i][0] == 0){
                column_one_zero = true;
                break;
            }
        }
        for(int i = 1; i < n; ++ i){
            for(int j = 1; j < m; ++ j){
                if(matrix[i][j] == 0){
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < n; ++ i){
            for(int j = 1; j < m; ++ j){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(row_one_zero){
            for(int i = 0; i < m; ++ i)
                matrix[0][i] = 0;
        }
        if(column_one_zero){
            for(int i = 0; i < n; ++ i)
                matrix[i][0] = 0;
        }
    }
};
