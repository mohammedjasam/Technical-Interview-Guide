/*
*
* Tag: Sort
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
    struct compare{
        bool operator() (const Interval &a, const Interval &b) const{
            return a.start == b.start?a.end < b.end:a.start < b.start;
        }
    }cmp;
    
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        if(intervals.size() == 0){
            return ans;
        }
        
        sort(intervals.begin(), intervals.end(), cmp);
        Interval cur(intervals[0].start, intervals[0].end);
        for(int i = 1; i < intervals.size(); ++ i){
            if(cur.end < intervals[i].start){
                ans.push_back(cur);
                cur = intervals[i];
            }else{
                cur.end = max(cur.end, intervals[i].end);
            }
        }
        ans.push_back(cur);
        
        return ans;
    }
};
