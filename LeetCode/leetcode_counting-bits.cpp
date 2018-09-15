/*
*
* TODO
* Tag: DP
* Time: O(n)
* Space: O(n)
*/
/*
*
* TODO
* Tag: DP
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        ans[0] = 0;
        if(!num) {
            return ans;
        }
        
        ans[1] = 1;
        if(num == 1) {
            return ans;
        }
        
        ans[2] = 1;
        int lowbnd = 2, upbnd = 4;
        for(int i = 3; i <= num; ++ i){
            if(i == upbnd){
                ans[i] = 1;
                lowbnd = upbnd;
                upbnd <<= 1;
            }else{
                int mask = i^lowbnd;
                ans[i] = ans[mask] + 1;
            }
        }
        
        return ans;
    }
};
