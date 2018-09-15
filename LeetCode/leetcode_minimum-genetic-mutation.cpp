/*
*
* Tag: BFS
* Time: O(m) where m is the size of dictionary
* Space: O(m)
*/
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,int> path;
        if(!bank.size())
            return -1;
        for(int i = 0; i < bank.size(); ++ i)
            path[bank[i]] = INT_MAX;
        path[start] = 0;
        queue<string> q;
        bool isReach = false;
        string u = "", v = "";
        q.push(start);
        while(!q.empty()){
            u = q.front();
            q.pop();
            for(int i = 0; i < 8; ++ i){
                v = u;
                for(int j = 0; j < 4; ++ j){
                    if(v[i] != gene[j]){
                        v[i] = gene[j];
                        if(path.count(v) && path[v] > path[u] + 1){
                            path[v] = path[u] + 1;
                            if(v == end){
                                return path[v];
                            }
                            q.push(v);
                        }
                    }
                }
            }
        }
        
        return -1;
    }
private:
    char gene[4] = {'A','C','G','T'};
};
