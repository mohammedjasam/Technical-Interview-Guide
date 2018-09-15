/*
*
* Tag: DP
* Time: O(nm^2)
* Space: O(n)
*/
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ans = 0;
        if(key.size() == 0) {
            return ans;
        }
        
        unordered_map<int,int> predp, curdp;
        unordered_map<int,int>::iterator it;
        int n = key.size(), m = ring.size(), k, idx, cnt, j;
        predp[0] = 0;
        for(int i = 0; i < n; ++ i){
            curdp.clear();
            
            for(it = predp.begin(); it != predp.end(); ++ it ){
                idx = it->first;
                
                for(int j = 0; j < m; ++ j){
                    if( ring[(idx + j)%m] == key[i] ){
                        if(curdp.find((idx + j)%m) == curdp.end())
                            curdp[(idx + j)%m] = predp[idx] + j + 1;
                        else
                            curdp[(idx + j)%m] = min(curdp[(idx + j)%m], predp[idx] + j + 1);
                        break;
                    }
                }
                for(int j = 0; j < m; ++ j){
                    if( ring[(idx - j + m)%m] == key[i] ){
                        if(curdp.find((idx - j + m)%m) == curdp.end())
                            curdp[(idx - j + m)%m] = predp[idx] + j + 1;
                        else
                            curdp[(idx - j + m)%m] = min(curdp[(idx - j + m)%m], predp[idx] + j + 1);
                        break;
                    }
                }
            }
            
            predp = curdp;
        }
        
        ans = INT_MAX;
        for(it = curdp.begin(); it != curdp.end(); ++ it) {
            ans = min(ans, it->second);
        }
        
        return ans;
    }
};
