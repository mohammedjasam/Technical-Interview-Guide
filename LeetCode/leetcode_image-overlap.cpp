/*
*
* Tag: Brute Force
* Time: O(n^4)
* Space: O(n^2)
*/
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ans = 0;
        if(A.size() == 0 || B.size() == 0){
            return ans;
        }
                
        for(int i = 0; i < A.size(); ++ i){
            for(int j = 0; j < A[0].size(); ++ j){
                vector<vector<int>> translatedA = translateImageStartingAtTranslatedImagePosition(A, i, j);
                ans = max(ans, countOverlapUnits(translatedA, B));
                
                translatedA = translateImageStartingAtOriginalImagePosition(A, i, j);
                ans = max(ans, countOverlapUnits(translatedA, B));
            }
        }
        
        return ans;
    }

private:
    vector<vector<int>> translateImageStartingAtTranslatedImagePosition(vector<vector<int>>& A, int startRow, int startColumn){
        int numOfRows = A.size(), numOfColumns = A[0].size();
        vector<vector<int>> image(numOfRows, vector<int>(numOfColumns, 0));
        for(int i = startRow, rowOfA = 0; i < numOfRows && rowOfA < numOfRows; ++ i, ++ rowOfA){
            for(int j = startColumn, columnOfA = 0; j < numOfColumns && columnOfA < numOfColumns; ++ j, ++ columnOfA){
                image[i][j] = A[rowOfA][columnOfA];
            }
        }
        
        return image;
    }
    
    vector<vector<int>> translateImageStartingAtOriginalImagePosition(vector<vector<int>>& A, int startRow, int startColumn){
        int numOfRows = A.size(), numOfColumns = A[0].size();
        vector<vector<int>> image(numOfRows, vector<int>(numOfColumns, 0));
        for(int i = 0, rowOfA = startRow; i < numOfRows && rowOfA < numOfRows; ++ i, ++ rowOfA){
            for(int j = 0, columnOfA = startColumn; j < numOfColumns && columnOfA < numOfColumns; ++ j, ++ columnOfA){
                image[i][j] = A[rowOfA][columnOfA];
            }
        }
        
        return image;
    }
    
    int countOverlapUnits(vector<vector<int>>& A, vector<vector<int>>& B){
        int ans = 0;
        for(int i = 0; i < A.size(); ++ i){
            for(int j = 0; j < A[0].size(); ++ j){
                ans += (A[i][j] & B[i][j]);
            }
        }
        
        return ans;
    }
};
