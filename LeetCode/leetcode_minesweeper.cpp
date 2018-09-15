/*
*
* Tag: Implementation && BFS
* Time: O(nm)
* Space: O(nm)
*/
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<char>> ans = board;
        if(board.size() == 0)
            return ans;
        queue<pair<int,int>> q;
        q.push(make_pair(click[0], click[1]));
        pair<int,int> cur, nxt;
        int n = ans.size(), m = ans[0].size(), cnt = 0;
        bool isfirst = true;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(ans[cur.first][cur.second] == 'M'){
                ans[cur.first][cur.second] = 'X';
                break;
            }
            if(ans[cur.first][cur.second] >= '1' && ans[cur.first][cur.second] <= '8')
                continue;
            if(isfirst){
                cnt = calMine(cur, board);
                if(cnt == 0){
                    ans[cur.first][cur.second] = 'B';
                } else {
                    ans[cur.first][cur.second] = ('0' + cnt);
                    break;
                }
                isfirst = false;
            }
            for(int i = 0; i < 8; ++ i){
                nxt.first = cur.first + dir[i][0], nxt.second = cur.second + dir[i][1];
                if( isInside(nxt, n, m) ){
                    if( ans[nxt.first][nxt.second] == 'E' ){
                        cnt = calMine(nxt, board);
                        if(cnt == 0){
                            ans[nxt.first][nxt.second] = 'B';
                            q.push(nxt);
                        }else{
                            ans[nxt.first][nxt.second] = ('0' + cnt);
                        }
                    }
                }
            }
        }
        return ans;
    }
private:
    bool isInside(pair<int,int> cur, int n, int m){
        return cur.first >= 0 && cur.first < n && cur.second >= 0 && cur.second < m;
    }
    
    int calMine(pair<int,int> cur, vector<vector<char>>& board){
        int res = 0, n = board.size(), m = board[0].size();
        pair<int,int> nxt = cur;
        for(int i = 0; i < 8; ++ i){
            nxt.first = cur.first + dir[i][0], nxt.second = cur.second + dir[i][1];
            if( isInside(nxt, n, m) && board[nxt.first][nxt.second] == 'M' )
                ++ res;
        }
        return res;
    }
    
private:
    int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1,1}, {1, -1}, {-1, 1}, {-1,-1}};
};
