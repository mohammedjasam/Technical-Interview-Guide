/*
*
* Tag:
* Time: O(n*m)
* Space: O(1)
*/
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() <= 1){
            return true;
        }
        
        int numOfRows = matrix.size(), numOfColumns = matrix[0].size();
        for(int r = 0; r < numOfRows; ++ r){
            for(int c = 0; c < numOfColumns; ++ c ){
                if(r > 0 && c > 0 && matrix[r][c] != matrix[r - 1][c - 1]){
                    return false;
                }
            }
        }
        
        return true;
    }
};
