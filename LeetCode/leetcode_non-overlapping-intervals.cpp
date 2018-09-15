/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int ans = 0, bnd = INT_MIN;
        if(!intervals.size())
            return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        for(int i = 0; i < intervals.size(); ++ i){
            if(bnd > intervals[i].start)
                ++ ans;
            else if(bnd < intervals[i].end)
                bnd = intervals[i].end;
        }
        return ans;
    }
private:
    static bool cmp(Interval &a, Interval &b){
        return a.end < b.end;
    }
};
