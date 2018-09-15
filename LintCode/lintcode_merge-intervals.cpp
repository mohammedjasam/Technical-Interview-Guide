/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/
/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {

public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    
    struct cmp{
        bool operator() (Interval a, Interval b) { 
            if(a.start == b.start)
                return a.end < b.end;
            return a.start < b.start;
        }
    }mycmp;
    
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        vector<Interval> ans;
        if(!intervals.size())
            return ans;
        sort(intervals.begin(), intervals.end(), mycmp);
        int n = intervals.size();
        for(int i = 0; i < n; ++ i){
            Interval tmp(intervals[i].start, intervals[i].end);
            int id = i + 1;
            for(; intervals[id].start <= tmp.end; ++ id){
                tmp.end = max(tmp.end, intervals[id].end);
            }
            i = id - 1;
            ans.push_back(tmp);
        }
        return ans;
    }
  
};
