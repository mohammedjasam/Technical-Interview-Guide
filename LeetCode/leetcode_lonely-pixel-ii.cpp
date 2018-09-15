/*
*
* Tag: Hash
* Time: O(nm)
* Space: O(nm)
*/
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int ans = 0;
        if(picture.size() == 0 || N == 0){
            return ans;
        }
        
        int n = picture.size(), m = picture[0].size();
        vector<int> rbcnt(n, 0), clcnt(m, 0);
        vector<string> rptn(n, "");
        vector<vector<int>> rclmp(m, vector<int>(0));
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(picture[i][j] == 'B'){
                    ++ rbcnt[i];
                    ++ clcnt[j];
                    rclmp[j].push_back(i);
                }
                rptn[i] += picture[i][j];
            }
        }
        for(int i = 0; i < m; ++ i){
            if(clcnt[i] == N){
                if(check(rbcnt, rptn, rclmp, i, N)) {
                    ans += N;
                }
            }
        }
        
        return ans;
    }
    
private:
    bool check(vector<int> &rbcnt, vector<string> &rptn, vector<vector<int>> &rclmp, int col, int N){
        string ptn = "";
        for(int i = 0; i < rclmp[col].size(); ++ i){
            if(i == 0) {
                ptn = rptn[rclmp[col][i]];
            } else if(ptn != rptn[rclmp[col][i]]) {
                return false;
            }
            
            if(rbcnt[rclmp[col][i]] != N) {
                return false;
            }
        }
        
        return true;
    }
};
