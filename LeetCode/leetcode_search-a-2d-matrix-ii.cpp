/*
*
* Tag: Two Pointers
* Time: O(n+m)
* Space: O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0){
            return false;
        }
        
        int n = matrix.size(), m = matrix[0].size();
        int i = n - 1, j = 0;
        while(i >= 0 && j < m){
            if(matrix[i][j] == target) {
                return true;
            } else if(matrix[i][j] > target) {
                -- i;
            } else {
                ++ j;
            }
        }
        
        return false;
    }
};
