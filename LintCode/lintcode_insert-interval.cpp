/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        if(!intervals.size()){
            intervals.push_back(newInterval);
            return intervals;
        }
        int n = intervals.size();
        vector<Interval> ans;
        bool isinserted = false;
        for(int i = 0; i < n; ++ i){
            if(newInterval.end < intervals[i].start){
                if(!isinserted){
                    ans.push_back(newInterval);
                    isinserted = true;
                }
                ans.push_back(intervals[i]);
            }else if(newInterval.start > intervals[i].end){
                ans.push_back(intervals[i]);
            }else{
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        if(!isinserted)
            ans.push_back(newInterval);
        return ans;
    }
};
