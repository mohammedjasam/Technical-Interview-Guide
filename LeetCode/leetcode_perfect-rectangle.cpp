/*
*
* Tag: Graph
* Time: O(n)
* Space: O(n)
*/
class Solution {

public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if(rectangles.size() == 0)
            return false;
        pair<long long,long long> btn, up;
        int n = rectangles.size(), key_x, key_y;
        long long cmp_area = 0, actual_area = 0;
        btn.first = btn.second = LLONG_MAX;
        up.first = up.second = LLONG_MIN;
        graph.clear();
        for(int i = 0; i < n; ++ i){
            key_x = rectangles[i][0], key_y = rectangles[i][1];
            if(graph.find(key_x) != graph.end() && graph[key_x].find(key_y) != graph[key_x].end())
                return false;
            graph[key_x][key_y] = make_pair(rectangles[i][2], rectangles[i][3]);
            btn.first = min(btn.first, (long long)rectangles[i][0]);
            btn.second = min(btn.second, (long long)rectangles[i][1]);
            up.first = max(up.first, (long long)rectangles[i][2]);
            up.second = max(up.second, (long long)rectangles[i][3]);
            cmp_area += ((long long)rectangles[i][2] - (long long)rectangles[i][0])*((long long)rectangles[i][3] - (long long)rectangles[i][1]);
        }
        actual_area = ((long long)up.first - (long long)btn.first)*((long long)up.second - (long long)btn.second);
        if(cmp_area != actual_area)
            return false;
        int cnt = 0;
        dfs(make_pair(btn.first, btn.second), cnt);
        return cnt == rectangles.size();
    }
private:
    void dfs(pair<int,int> sta, int &cnt){
        stack<pair<int,int>> stk;
        pair<int,int> u, v;
        stk.push(sta);
        while(!stk.empty()){
            u = stk.top();
            stk.pop();
            if(graph.find(u.first) != graph.end() && graph[u.first].find(u.second) != graph[u.first].end()){
                ++ cnt;
                v = graph[u.first][u.second];
                graph[u.first].erase(u.second);
                if(graph[u.first].size() == 0)
                    graph.erase(u.first);
                stk.push(v);
                stk.push(make_pair(u.first, v.second));
                stk.push(make_pair(v.first, u.second));
            }
        }
    }
    
private:
    unordered_map<int,unordered_map<int,pair<int,int>>> graph;
};
