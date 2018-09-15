/*
*
* Tag: BFS
* Time: O(n^2)
* Space: O(n^2)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dir[4][2] = {0,-1,0,1,-1,0,1,0};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin>>T;
    while(T --){
        int n, m, k;
        cin>>n>>m;
        vector<string> mp;
        vector<vector<int> > vis;
        vector<vector<bool> > chk;
        for(int i = 0; i < n; i ++){
            string inp;
            vector<int> tmp;
            vector<bool> chp;
            tmp.resize(m);
            chp.resize(m);
            vis.push_back(tmp);
            chk.push_back(chp);
            cin>>inp;
            mp.push_back(inp);
        }
        cin>>k;
        pair<int,int> stap, endp;
        queue<pair<int,int> > q;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(mp[i][j] == 'M'){
                    stap.first = i;
                    stap.second = j;
                    q.push(stap);
                }else if(mp[i][j] == '*'){
                    endp.first = i;
                    endp.second = j;
                }
            }
        }
        chk[stap.first][stap.second] = true;
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            if(cur.first == endp.first && cur.second == endp.second)
                break;
            int cnt = 0;
            for(int i = 0; i < 4; i ++){
                int x = cur.first + dir[i][0], y = cur.second + dir[i][1];
                if(x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                if(mp[x][y] == 'X' || chk[x][y])
                    continue;
                cnt ++;
            }
            if(cnt == 0)
                continue;
            for(int i = 0; i < 4; i ++){
                int x = cur.first + dir[i][0], y = cur.second + dir[i][1];
                if(x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == 'X' || chk[x][y])
                    continue;
                chk[x][y] = true;
                if(cnt > 1){
                    vis[x][y] = vis[cur.first][cur.second] + 1;
                }else{
                    vis[x][y] = vis[cur.first][cur.second];
                }
                pair<int,int> np;
                np.first = x;
                np.second = y;
                q.push(np);
            }
        }
        if(vis[endp.first][endp.second] == k)
            cout<<"Impressed"<<endl;
        else
            cout<<"Oops!"<<endl;
    }
    return 0;
}
