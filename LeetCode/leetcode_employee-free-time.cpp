/*
*
* Tag: Greedy
* Time: O(nlgn) n is the number of intervals
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
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> ans;
        if(schedule.size() == 0){
            return ans;
        }
        
        vector<Interval> allIntervals;
        for(vector<Interval> freeTimes : schedule){
            for(Interval freeTime : freeTimes){
                allIntervals.push_back(freeTime);
            }
        }
        
        sort(allIntervals.begin(), allIntervals.end(), cmp);
        
        int curIntervalEndTime = allIntervals[0].end;
        for(int i = 1; i < allIntervals.size(); ++ i){
            int nextIntervalStartTime = allIntervals[i].start;
            if(curIntervalEndTime < nextIntervalStartTime) {
                Interval freeInterval(curIntervalEndTime, nextIntervalStartTime);
                ans.push_back(freeInterval);
            }
            
            curIntervalEndTime = max(curIntervalEndTime, allIntervals[i].end);
        }
        
        return ans;
    }
private:
    struct intervalComparator{
        bool operator() (const Interval &a, const Interval &b){
            return a.start == b.start ? a.end < b.end : a.start < b.start;
        }
    }cmp;
};
