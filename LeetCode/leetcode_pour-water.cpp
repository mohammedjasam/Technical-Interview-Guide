/*
*
* Tag: Implementation
* Time: O(vn)
* Space: O(n)
*/
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        if(V == 0 || heights.size() == 0){
            return heights;
        }
        
        vector<int> ans(heights);
        
        for(int i = 0; i < V; ++ i){
            int targetIndex = K;
            for(int j = K - 1; j >= 0; -- j){
                if(ans[j] > ans[j + 1]) {
                    break;
                } else if(ans[j] < ans[j + 1]) {
                    targetIndex = j;
                }
            }
            
            if(targetIndex != K && ans[targetIndex] < ans[K]){
                ++ ans[targetIndex];
                continue;
            }
            
            targetIndex = K;
            for(int j = K + 1; j < ans.size(); ++ j){
                if(ans[j] > ans[j - 1]) {
                    break;
                } else if(ans[j] < ans[j - 1]) {
                    targetIndex = j;
                }
            }
            
            if(targetIndex != K && ans[targetIndex] < ans[K]){
                ++ ans[targetIndex];
                continue;
            }
            
            ++ ans[K];
            
        }
        
        return ans;
    }
};
