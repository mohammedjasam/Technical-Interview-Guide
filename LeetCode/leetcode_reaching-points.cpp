/*
*
* Tag: Math
* Time: O(lg(max(tx, ty))
* Space: O(1)
*/
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(sx <= tx && sy <= ty){
            if(tx == ty){
                break;
            } else if(tx > ty) {
                if(ty > sy) {
                    tx %= ty;
                } else{
                    return (tx - sx)%ty == 0;
                }
            } else {
                if(tx > sx) {
                    ty %= tx;
                } else{
                    return (ty - sy)%tx == 0;
                }
            }
        }
        
        return sx == tx && sy == ty;
    }
};
