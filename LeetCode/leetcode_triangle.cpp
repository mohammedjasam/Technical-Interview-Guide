/*
* Algorithm: DP
* Time complexity: O(n^2)
* Memory complexity: O(1)
*/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int len = triangle.size();
        for(int i = len - 2; i >= 0; i --){
            for(int j = 0; j < triangle[i].size(); j ++){
                triangle[i][j] = min(triangle[i][j] + triangle[i + 1][j], triangle[i][j] + triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};

