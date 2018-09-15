/*
*
* Tag: BFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ans;
        if(!n)
            return ans;
        if(n == 1){
            ans.push_back(0);
            return ans;
        }
        vector<int> deg(n);
        for(int i = 0; i < edges.size(); ++ i){
            ++ deg[edges[i].first];
            ++ deg[edges[i].second];
        }
        vector<unordered_set<int>> mp(n);
        for(int i = 0; i < edges.size(); ++ i){
            mp[edges[i].first].insert(edges[i].second);
            mp[edges[i].second].insert(edges[i].first);
        }
        vector<int> q1(n), q2(n);
        int front1 = 0, rear1 = 0, rear2 = 0, num = n;
        for(int i = 0; i < n; ++ i){
            if(deg[i] == 1){
                q1[rear1 ++] = i;
                -- deg[i];
            }
        }
        
        if(n == 2){
            for(int i = 0; i < n; ++ i)
                ans.push_back(i);
        }else{
            while(front1 < rear1){
                rear2 = 0;
                while(front1 < rear1){
                    int cur = q1[front1 ++];
                    unordered_set<int>::iterator it = mp[cur].begin();
                    -- num;
                    for(; it != mp[cur].end(); ++ it){
                        -- deg[*it];
                        if(deg[*it] == 1){
                            q2[rear2 ++] = *it;
                        }
                    }
                }
                
                for(int i = 0; i < rear2; ++ i)
                    q1[rear1 ++] = q2[i];
                    
                if(num <= 2)
                    break;
            }
            
            ans.resize(rear1 - front1);
            ans[0] = q1[front1];
            if(rear1 - front1 == 2)
                ans[1] = q1[front1 + 1];
        }
        
        return ans;
    }
};
