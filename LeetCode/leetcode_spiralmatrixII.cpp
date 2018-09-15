/*
* Algorithm: Brute force, implementation
* Time complexity: O(n^2)
* Memory complexity: O(n^2)
*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ans(n,vector<int>(0) );
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                ans[i].push_back(0);
            }
        }
        int i = 0, j = 0, op = 0, cnt = 1;
        if(n*n == 1){ans[0][0] = 1;return ans;}
        while(cnt<=n*n){
            if(op == 0){
                ans[i][j] = cnt;
                j ++;
                cnt ++;
                if(j >= n || ans[i][j]) {j --;i ++;op = 1;}
            }else if(op == 1){
                ans[i][j] = cnt;
                i ++;
                cnt ++;
                if(i >= n || ans[i][j]) {i --;j--;op = 2;}
            }else if(op == 2){
                ans[i][j] = cnt;
                j --;
                cnt ++;
                if(j < 0 || ans[i][j]) {j ++;i--;op = 3;}
            }else{
                ans[i][j] = cnt;
                i --;
                cnt ++;
                if(i < 0 || ans[i][j]) {i ++;j ++;op = 0;}
            }
        }
        return ans;
    }
};
