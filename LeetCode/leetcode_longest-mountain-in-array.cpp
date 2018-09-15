/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int ans = 0;
        if(A.size() == 0){
            return ans;
        }
        
        bool climbUp = false;
        int mountainLen = 0;
        for(int i = 1; i < A.size(); ++ i){
            if(A[i] > A[i - 1]){
                if(!climbUp){
                    climbUp = true;
                    mountainLen = 1;
                }
                
                ++ mountainLen;
            } else if(A[i] < A[i - 1]) {
                if(!climbUp){
                    continue;
                }
                
                while(i < A.size() && A[i] < A[i - 1]) {
                    ++ i;
                    ++ mountainLen;
                }
                --i;
                
                climbUp = false;
                ans = max(ans, mountainLen);
            } else {
                climbUp = false;
            }
        }
        
        return ans;
    }
};
