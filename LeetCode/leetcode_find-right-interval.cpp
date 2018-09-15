/*
*
* Tag: Binary Search
* Time: O(n)
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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> ans;
        if(!intervals.size())
            return ans;
        map<int,int> dict;
        vector<int> startPntArr;
        for(int i = 0; i < intervals.size(); ++ i){
            if(dict.find(intervals[i].start) == dict.end())
                dict[intervals[i].start] = i;
            dict[intervals[i].start] = min(dict[intervals[i].start], i);
        }
        startPntArr.resize(dict.size());
        ans.resize(intervals.size());
        
        map<int,int>::iterator it = dict.begin();
        for(int i = 0; it != dict.end(); ++ it, ++ i){
            startPntArr[i] = it->first;
        }
        
        for(int i = 0; i < intervals.size(); ++ i){
            ans[i] = getRightIntervalIndex(startPntArr, intervals[i].end, dict);
        }
        
        return ans;
    }
    
private:
    int getRightIntervalIndex(vector<int> &startPntArr, int target, map<int,int> &dict){
        if(target <= startPntArr[0])
            return dict[startPntArr[0]];
        if(target > startPntArr[startPntArr.size() - 1])
            return -1;
        
        int l = 0, r = startPntArr.size() - 1, mid = 0;
        while(l < r){
            mid = l + ((r - l)>>1);
            if(target > startPntArr[mid]){
                l = mid + 1;
            }else
                r = mid;
        }
        
        return dict[startPntArr[r]];
    }

};
