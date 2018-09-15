/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(1)
*/
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.size() == 0) return ;
        vector<vector<int> > tmp(matrix.size(),vector<int>(0));
        int ix = 0, iy = 0;
        for(int i = matrix.size() - 1; i >= 0; i --){
            for(int j = 0; j < matrix[i].size(); j ++){
                tmp[j].push_back(matrix[i][j]);
            }
        }
        for(int i = 0; i < matrix.size(); i ++){
            for(int j = 0; j < matrix[i].size(); j ++){
                matrix[i][j] = tmp[i][j];
            }
        }
    }
};
