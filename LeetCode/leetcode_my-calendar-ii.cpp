/*
*
* Tag: Binary Search Tree
* Time: O(n^2)
* Space: O(n)
*/
class MyCalendarTwo {
private:
    map<int, int> timeScheduler;
public:
    MyCalendarTwo() {
        timeScheduler.clear();
    }
    
    bool book(int start, int end) {
        timeScheduler[start] = timeScheduler.count(start) == 0? 1 : timeScheduler[start] + 1;
        timeScheduler[end] = timeScheduler.count(end) == 0? -1 : timeScheduler[end] - 1;
        
        int delta = 0;
        for(auto it = timeScheduler.begin(); it != timeScheduler.end(); ++ it){
            delta += it->second;
            if(delta >= 3){
                -- timeScheduler[start];
                ++ timeScheduler[end];
                
                if(timeScheduler[start] == 0){
                    timeScheduler.erase(start);
                }
                
                if(timeScheduler[end] == 0){
                    timeScheduler.erase(end);
                }
                
                return false;
            }
        }
                
        return true;
    }
};

/*
*
* Tag: Binary Search Tree
* Time: O(t^2) where t is all the possible time point
* Space: O(t)
*/
class MyCalendarTwo {
private:
    map<int, pair<int, int>> timeScheduler;
public:
    MyCalendarTwo() {
        timeScheduler.clear();
    }
    
    bool book(int start, int end) {
        auto it = timeScheduler.upper_bound(start);
        if(it == timeScheduler.end()){
            timeScheduler[end] = make_pair(start, 1);
            return true;
        }
        
        for(auto tmpIt = it; tmpIt != timeScheduler.end() && tmpIt->second.first <= end; ++ tmpIt){
            if(start < tmpIt->first && tmpIt->second.first < end && tmpIt->second.second == 2){
                return false;
            }
        }        
        
        int curStart = start, overlappedCnt = 0;
        for(; it != timeScheduler.end(); ++ it){
            if(end <= it->second.first){
                timeScheduler[end] = make_pair(curStart, 1);
                return true;
            }
            
            if(it->second.first == curStart){
                if(it->first == end){
                    ++ it->second.second;
                    return true;
                } else if(it->first < end){
                    ++ it->second.second;
                    curStart = it->first;
                } else {
                    overlappedCnt = it->second.second;
                    timeScheduler[it->first] = make_pair(end, overlappedCnt);
                    timeScheduler[end] = make_pair(curStart, overlappedCnt + 1);
                    return true;
                }
                
            } else if(curStart < it->second.first){
                timeScheduler[it->second.first] = make_pair(curStart, 1);
                
                if(it->first == end){
                    ++ it->second.second;
                    return true;
                } else if(it->first < end){
                    ++ it->second.second;
                    curStart = it->first;
                } else {
                    overlappedCnt = it->second.second;
                    timeScheduler[end] = make_pair(it->second.first, overlappedCnt + 1);
                    timeScheduler[it->first] = make_pair(end, overlappedCnt);
                    return true;
                }
                
            } else {
                overlappedCnt = it->second.second;
                timeScheduler[curStart] = make_pair(it->second.first, overlappedCnt);
                
                if(it->first == end){
                    it->second.first = curStart;
                    ++ it->second.second;
                    return true;
                } else if(it->first < end){
                    it->second.first = curStart;
                    ++ it->second.second;
                    curStart = it->first;
                } else {
                    timeScheduler[it->first] = make_pair(end, overlappedCnt);
                    timeScheduler[end] = make_pair(curStart, overlappedCnt + 1);
                    return true;
                }
                
            }
        }
        timeScheduler[end] = make_pair(curStart, 1);
                
        return true;
    }
};
