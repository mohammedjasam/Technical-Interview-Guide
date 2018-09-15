/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool canTransform(string start, string end) {
        if(start.size() != end.size()){
            return false;
        }
        
        int numOfL = 0, numOfR = 0;
        int n = start.size();
        for(int i = 0; i < n; ++ i){
            if(start[i] == 'L'){
                ++ numOfL;
            } else {
                ++ numOfR;
            }
            
            if(end[i] == 'L'){
                -- numOfL;
            } else {
                -- numOfR;
            }
        }
        if(numOfL != 0 || numOfR != 0){
            return false;
        }
        
        for(int i = 0, j = 0; i < n && j < n; ){
            while(i < n && start[i] == 'X') {
                ++ i;
            }
            while(j < n && end[j] == 'X') {
                ++ j;
            }
            
            if(i == n && j == n){
                break;
            }
            
            if((i == n && j < n) || (i < n && j == n) || start[i] != end[j]){
                return false;
            }
            
            if((i > j && start[i] == 'R') || (i < j && start[i] == 'L')){
                return false;
            }
            
            ++ i, ++ j;
        }
        
        return true;
    }
};
