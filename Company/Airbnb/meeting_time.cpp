/*
*
* Tag: Data Structure
* Time: O(nlgn)
* Space: O(n)
*/
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <cmath>
#include <ctype.h>
#include <climits>
#include <utility>
using namespace std;

class MeetingTimeScheduler {
private:
    map<int,int> timePointCounter;
public:
    vector<pair<int,int>> findIntervals(vector<vector<pair<int,int>>> intervalsOfPeople, int k) {
        vector<pair<int,int>> ans;
        if(intervalsOfPeople.size() == 0 || k < 0){
            return ans;
        }
        
        init();
        
        for(vector<pair<int,int>> people : intervalsOfPeople){
            for(pair<int,int> interval : people){
                ++ timePointCounter[interval.first];
                -- timePointCounter[interval.second];
            }
        }
        
        int startTime = -1, endTime = -1;
        int count = 0, numOfPeople = intervalsOfPeople.size();
        for(auto it = timePointCounter.begin(); it != timePointCounter.end(); ++ it){
            int timePoint = it->first;
            count += it->second;
            
            //cout<<timePoint<<" -- "<<it->second<<endl;
            
            if(startTime == -1) {
                if(count <= numOfPeople - k) {
                    startTime = timePoint;
                    endTime = max(endTime, timePoint);
                }
            } else {
                endTime = max(endTime, timePoint);
                if(count == numOfPeople - k + 1) {
                    ans.push_back(make_pair(startTime, endTime));
                    startTime = endTime = -1;
                }
            }
            
        }
        if(count <= numOfPeople - k && startTime != -1 && startTime != endTime){
            ans.push_back(make_pair(startTime, endTime));
        }
        
        return ans;
    }
    
private:
    void init(){
        timePointCounter.clear();
    }
};

int main() {
//    cout<<"Hi"<<endl;
    MeetingTimeScheduler mts;
    vector<vector<pair<int,int>>> test1 = {
        {make_pair(1, 3), make_pair(5, 7)},
        {make_pair(6, 9)}
    };
    vector<pair<int,int>> ans1 = mts.findIntervals(test1, 2);
    for(pair<int,int> interval : ans1){
        cout<<interval.first<<" "<<interval.second<<endl;
    }
    cout<<endl;
    
    vector<vector<pair<int,int>>> test2 = {
        {make_pair(1, 3), make_pair(6, 7)},
        {make_pair(2, 4)},
        {make_pair(2, 3), make_pair(9, 12)}
    };
    vector<pair<int,int>> ans2 = mts.findIntervals(test2, 3);
    for(pair<int,int> interval : ans2){
        cout<<interval.first<<" "<<interval.second<<endl;
    }
    cout<<endl;
    
    vector<vector<pair<int,int>>> test3 = {
        {make_pair(1, 3), make_pair(6, 7)},
        {make_pair(2, 3), make_pair(9, 12)}
    };
    vector<pair<int,int>> ans3 = mts.findIntervals(test3, 0);
    for(pair<int,int> interval : ans3){
        cout<<interval.first<<" "<<interval.second<<endl;
    }
    cout<<endl;
    
    return 0;
}
