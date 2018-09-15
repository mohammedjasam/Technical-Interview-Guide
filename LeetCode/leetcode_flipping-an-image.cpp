/*
*
* Tag: Implementation
* Time: O(n*m)
* Space: O(1)
*/
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> ans(A);
        if(A.size() == 0){
            return ans;
        }
        
        reverseImage( ans );
        
        invertImage( ans );
        
        return ans;
    }
private:
    void reverseImage(vector<vector<int>>& A){
        for(int i = 0; i < A.size(); ++ i){
            reverse(A[i].begin(), A[i].end());
        }
    }
    
    void invertImage(vector<vector<int>>& A) {
        for(int i = 0; i < A.size(); ++ i){
            for(int j = 0; j < A[i].size(); ++ j){
                A[i][j] ^= 1;
            }
        }
    }
};
