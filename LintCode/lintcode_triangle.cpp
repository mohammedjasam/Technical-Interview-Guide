/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        int ans = INT_MAX;
        int r = triangle.size();
        for(int i = 1; i < r; ++ i){
            for(int j = 0; j <= i; ++ j){
                if(!j)
                    triangle[i][j] += triangle[i - 1][j];
                else if(j < i)
                    triangle[i][j] = min(triangle[i][j] + triangle[i - 1][j],triangle[i][j] + triangle[i - 1][j - 1]);
                else
                    triangle[i][j] += triangle[i - 1][j - 1];
            }
        }
        for(int i = 0; i < r; ++ i){
            ans = min(ans, triangle[r - 1][i]);
        }
        return ans;
    }
};
