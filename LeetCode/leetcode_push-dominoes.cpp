/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    string pushDominoes(string dominoes) {
        if(dominoes.size() == 0){
            return dominoes;
        }
        
        string ans = dominoes;
        int pointerOfL = 0, pointerOfR = 0;
        for(int i = 0; i < ans.size(); ++ i){
            if(ans[i] == 'L') {
                for(int j = i - 1; j >= 0; -- j){
                    if(ans[j] == 'L'){
                        break;
                    }
                    
                    ans[j] = 'L';
                }
            } else if(ans[i] == 'R') {
                pointerOfR = i;
                pointerOfL = -1;
                int j = 0;
                for(j = i + 1; j < ans.size(); ++ j){
                    if(ans[j] == '.') {
                        continue;
                    }
                    
                    if(ans[j] == 'L'){
                        pointerOfL = j;
                    }
                    break;
                }
                                
                while(pointerOfR < j){
                    if(pointerOfR >= pointerOfL && pointerOfL >= 0){
                        break;
                    }
                    ans[pointerOfR] = 'R';
                    ++ pointerOfR;
                    if(pointerOfL >= 0){
                        ans[pointerOfL] = 'L';
                        -- pointerOfL;
                    }
                }
                
                i = j;
                if(i < ans.size() && ans[i] == 'R') {
                    -- i;
                }
            }
        }
        
        return ans;
    }
};
