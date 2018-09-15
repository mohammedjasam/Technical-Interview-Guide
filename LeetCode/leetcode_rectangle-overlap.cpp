/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1.size() == 0 || rec2.size() == 0){
            return true;
        }
        
        return rec1[0] < rec2[2] && rec2[0] < rec1[2] && rec1[1] < rec2[3] && rec2[1] < rec1[3];
    }
};
