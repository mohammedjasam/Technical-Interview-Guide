/*
*
* Tag: Binary Search Tree (Data Structure)
* Time: O(nlgn)
* Space: O(n)
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    map<int,int> meetingRoomScheduler;
public:
    Solution(){
        meetingRoomScheduler.clear();
    }
    
    int minMeetingRooms(vector<Interval>& intervals) {
        int ans = 0;
        if(intervals.size() == 0){
            return ans;
        }
        
        for(Interval interval : intervals){
            ++ meetingRoomScheduler[interval.start];
            -- meetingRoomScheduler[interval.end];
        }
        
        int numOfMeetingRooms = 0;
        for(auto it = meetingRoomScheduler.begin(); it != meetingRoomScheduler.end(); ++ it){
            numOfMeetingRooms += it->second;
            ans = max(ans, numOfMeetingRooms);
        }
        
        return ans;
    }
};
