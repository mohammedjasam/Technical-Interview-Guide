/*
*
* Tag: Bit Manipulation
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    int binaryGap(int N) {
        int ans = 0;
        int curPos = -1, lastPos = -1, pos = 0;
        while(N > 0){
            if(N&1 == 1){
                lastPos = curPos;
                curPos = pos;
            }
            
            if(lastPos >= 0){
                ans = max(ans, curPos - lastPos);
            }
            
            N >>= 1;
            ++ pos;
        }
        
        return ans;
    }
};
