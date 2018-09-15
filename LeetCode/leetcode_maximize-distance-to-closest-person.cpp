/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        if(seats.size() < 2){
            return 0;
        }
        
        int rightMostSeatNum = seats.size() - 1;
        int maxDistance = 0;
        int leftMostGuestPos = rightMostSeatNum, rightMostGuestPos = 0;
        for(int i = 0; i < seats.size(); ++ i){
            if(seats[i] == 1){
                leftMostGuestPos = min(leftMostGuestPos, i);
                rightMostGuestPos = max(rightMostGuestPos, i);
            }
        }
        
        if(seats[0] == 0){
            maxDistance = leftMostGuestPos;
        }
        
        if(seats[rightMostSeatNum] == 0){
            if(maxDistance < rightMostSeatNum - rightMostGuestPos) {
                maxDistance = rightMostSeatNum - rightMostGuestPos;
            }
        }
        
        int currentLeftGuest = leftMostGuestPos;
        for(int currentRightGuest = leftMostGuestPos + 1; currentRightGuest <= rightMostGuestPos; ++ currentRightGuest){
            if(seats[currentRightGuest] == 1){
                int currentMaxDistance = (currentRightGuest - currentLeftGuest)/2;
                
                if(currentMaxDistance > maxDistance){
                    maxDistance = currentMaxDistance;
                }
                
                currentLeftGuest = currentRightGuest;
            }
        }
        
        return maxDistance;
    }
};
