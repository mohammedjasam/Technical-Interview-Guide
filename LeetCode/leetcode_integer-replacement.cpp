/*
*
* Tag: BFS
* Time: O(lgn)
* Space: O(lgn)
*/
class Solution {
private:
    unordered_map<int,int> vis;
public:
    int integerReplacement(int n) {
        if(n <= 1)
            return 0;
        vis.clear();
        queue<long long> q;
        long long u = 0, v = 0;
        q.push(n);
        vis[n] = 0;
        while(!q.empty()){
            u = q.front();
            q.pop();
            if(u%2 == 1){
                v = u + 1;
                if(vis.find(v) == vis.end()){
                    vis[v] = vis[u] + 1;
                    q.push(v);
                }
                v = u - 1;
                if(vis.find(v) == vis.end()){
                    vis[v] = vis[u] + 1;
                    q.push(v);
                }
            }else{
                v = u/2;
                if(vis.find(v) == vis.end()){
                    vis[v] = vis[u] + 1;
                    q.push(v);
                }
            }
        }
        
        return vis[1];
    }
};
