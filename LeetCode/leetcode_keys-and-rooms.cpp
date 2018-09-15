/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
private:
    int numOfRoomsVisited;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visitedRooms(rooms.size());
        if(rooms.size() == 0){
            return true;
        }
        
        numOfRoomsVisited = 0;
        dfs(0, rooms, visitedRooms);
        
        return numOfRoomsVisited == rooms.size();
    }
    
private:
    void dfs(int currentRoom, vector<vector<int>>& rooms, vector<bool> &visitedRooms){
        visitedRooms[currentRoom] = true;
        ++ numOfRoomsVisited;
        
        for(int nextRoom : rooms[currentRoom]) {
            if(!visitedRooms[nextRoom]) {
                dfs(nextRoom, rooms, visitedRooms);
            }
        }
    }
};
