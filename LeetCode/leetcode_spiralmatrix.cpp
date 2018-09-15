/*
* Algorithm: Brute force, Implement
* Time complexity: O(mn)
* Memory complexity: O(mn)
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        ans.clear();
        if(matrix.size() == 0) return ans;
        int i = 0, j = 0, op = 0, cnt = 0;
        int n = matrix[0].size(), m = matrix.size();
        if(n==1 && m==1){
            ans.push_back(matrix[0][0]);
            return ans;
        }
        vector<vector<bool> > vis(m + 2, vector<bool>(n + 2, false));
        while(cnt<m*n){
            if(op == 0){
                ans.push_back(matrix[i][j]);
                vis[i][j] = 1;
                j ++;
                cnt ++;
                if(j >= n || vis[i][j]) {j --;i ++;op = 1;}
            }else if(op == 1){
                ans.push_back(matrix[i][j]);
                vis[i][j] = 1;
                i ++;
                cnt ++;
                if(i >= m || vis[i][j]) {i --;j--;op = 2;}
            }else if(op == 2){
                ans.push_back(matrix[i][j]);
                vis[i][j] = 1;
                j --;
                cnt ++;
                if(j < 0 || vis[i][j]) {j ++;i--;op = 3;}
            }else{
                ans.push_back(matrix[i][j]);
                vis[i][j] = 1;
                i --;
                cnt ++;
                if(i < 0 || vis[i][j]) {i ++;j ++;op = 0;}
            }
        }
        return ans;
    }
};
