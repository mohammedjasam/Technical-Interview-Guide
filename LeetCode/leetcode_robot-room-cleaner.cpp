/*
*
* TODO
* Tag: DFS
* Time: O(nm)
* Space: O(nm)
*/
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
private:
    pair<int,int> curPos;
    unordered_map<int, unordered_set<int>> visitedPos;
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int curDir;
public:
    Solution(){
        curPos.first = curPos.second = 0;
        curDir = 0;
    }
    
    void cleanRoom(Robot& robot) {
        if(visitedPos[curPos.first].count(curPos.second) != 0){
            return ;
        }
        
        visitedPos[curPos.first].insert(curPos.second);
        robot.clean();
        
        for(int i = 0; i < 4; ++ i){
            if(robot.move()){
                curPos.first += dir[curDir][0];
                curPos.second += dir[curDir][1];
                cleanRoom(robot);
                
                robot.turnRight();
                robot.turnRight();
                robot.move();
                curPos.first -= dir[curDir][0];
                curPos.second -= dir[curDir][1];
                
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
            curDir = (curDir + 1)%4;
        }
        
        return ;
    }
};
