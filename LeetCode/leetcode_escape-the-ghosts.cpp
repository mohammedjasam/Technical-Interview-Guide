/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int> source = {0, 0};
        for(vector<int> ghost : ghosts){
            if(manhattanDistance(ghost, target) <= manhattanDistance(source, target)){
                return false;
            }
        }
        
        return true;
    }
private:
    int manhattanDistance(vector<int> source, vector<int> target){
        return abs(source[0] - target[0]) + abs(source[1] - target[1]);
    }
};
