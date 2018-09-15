/*
*
* Tag: Brute Force
* Time: O(m + n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int cnt = 0;
        if(matrix.size() == 0)
            return cnt;
        int n = matrix.size(), m = matrix[0].size();
        int ir = n - 1, ic = m - 1;
        for(; ic >= 0; -- ic){
            if(matrix[0][ic] <= target)
                break;
        }
        if(ic < 0)
            return 0;
        for(int i = 0; i < n; ++ i){
            if(matrix[i][ic] == target)
                ++ cnt;
            else if(matrix[i][ic] > target)
                break;
        }
        
        int icc = 0;
        for(; icc < ic; ++ icc){
            if(matrix[n - 1][icc] >= target)
                break;
        }
        if(icc == ic)
            return cnt;
        for(int i = n - 1; i >= 0; -- i){
            if(matrix[i][icc] == target)
                ++ cnt;
            else if(matrix[i][icc] < target)
                break;
        }
        for(int i = icc + 1; i < ic; ++ i){
            if(matrix[0][i] < target && matrix[n - 1][i] < target)
                continue;
            if(matrix[0][i] == target && matrix[n - 1][i] == target){
                cnt += n;
                continue;
            }
            if(matrix[0][i] <= target && matrix[n - 1][i] >= target){
                for(int j = 0; j < n; ++ j)
                    if(matrix[j][i] == target)
                        ++ cnt;
                    else if(matrix[j][i] > target)
                        break;
            }
        }
//        cnt += (ic - icc - 1)*n;
        return cnt;
    }
};
