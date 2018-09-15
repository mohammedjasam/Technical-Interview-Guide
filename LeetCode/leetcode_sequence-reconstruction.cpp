/*
*
* Tag: Topological Sort
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if(!org.size() || !seqs.size())
            return false;
        
        unordered_map<int, unordered_set<int>> graph;
        vector<int> deg(org.size() + 1, 0);
        
        for(int i = 0; i < seqs.size(); ++ i){
            for(int j = 0; j < seqs[i].size(); ++ j){
                if(seqs[i][j] > org.size() || seqs[i][j] <= 0){
                    return false;
                }
                if(!j)
                    continue;
                if(!graph[seqs[i][j-1]].count(seqs[i][j]))
                    ++ deg[seqs[i][j]];
                graph[seqs[i][j-1]].insert(seqs[i][j]);
            }
        }
        
        return topoSort(graph, deg, org);
    }

private:
    bool topoSort(unordered_map<int, unordered_set<int>> &graph, vector<int> &deg, vector<int> &org){
        vector<int> que(org.size() + 1), tmpque(org.size() + 1);
        int fnt1 = 0, bk1 = 0, fnt2 = 0, bk2 = 0, cnt = 0, u = 0, v = 0;
        unordered_set<int>::iterator it;
        
        for(int i = 1; i < deg.size(); ++ i){
            if(deg[i] == 0){
                que[bk1 ++] = i;
         //       printf("-- %d\n",i);
            }
        }
        
        while(fnt1 < bk1){
            if(bk1 - fnt1 > 1){
           //     printf("fnt = %d, bk = %d\n",fnt1, bk1);
                return false;
            }
            u = que[fnt1 ++];
            if(u != org[cnt]){
               // printf("%d %d\n", u, org[cnt]);
                return false;
            }
            ++ cnt;
            fnt2 = bk2 = 0;
            for(it =  graph[u].begin(); it != graph[u].end(); ++ it){
                v = *it;
                -- deg[v];
                if(deg[v] == 0)
                    tmpque[bk2 ++] = v;
            }
            
            fnt1 = bk1 = 0;
            while(fnt2 < bk2)
                que[bk1 ++] = tmpque[fnt2], fnt2 ++;
        }
        
        return cnt == org.size();
    }
    
};
