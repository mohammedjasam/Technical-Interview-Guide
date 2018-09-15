/*
*
* Tag: Binary Search
* Time: O(log(n*m))
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.size() == 0)
            return false;
        int rw = matrix.size(), clm = matrix[0].size();
        int l = 0, r = rw*clm - 1;
        while(l >= 0 && l <= r && r <= rw*clm - 1){
            int mid = (l + r)>>1;
            int midrw = mid/clm, midclm = mid%clm;
            if(matrix[midrw][midclm] == target)
                return true;
            else if(matrix[midrw][midclm] < target){
                if(midclm == clm - 1){
                    midrw ++;
                    midclm = 0;
                }else{
                    midclm ++;
                }
                l = midrw*clm + midclm;
            }else{
                if(midclm == 0){
                    midrw --;
                    midclm = clm - 1;
                }else{
                    midclm --;
                }
                r = midrw*clm + midclm;
            }
        }
        return false;
    }
};

