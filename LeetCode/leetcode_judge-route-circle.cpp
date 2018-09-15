/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool judgeCircle(string moves) {
        if(moves.size() == 0)
            return true;
        
        pair<int,int> curPoint(0 , 0), originalPoint(0, 0);
        for(int i = 0; i < moves.size(); ++ i){            
            if(moves[i] == 'U')
                curPoint = make_pair(curPoint.first - 1, curPoint.second);
            else if(moves[i] == 'D')
                curPoint = make_pair(curPoint.first + 1, curPoint.second);
            else if(moves[i] == 'L')
                curPoint = make_pair(curPoint.first, curPoint.second - 1);
            else
                curPoint = make_pair(curPoint.first, curPoint.second + 1);            
        }
        
        return curPoint == originalPoint;
    }
};
