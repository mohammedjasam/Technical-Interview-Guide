/*
*
* Tag: Data Structure (Binary Search Tree)
* Time: O(lgn)
* Space: O(n)
*/
class MyCalendar {
private:
    map<int,int> scheduledEvent;
public:
    MyCalendar() {
        scheduledEvent.clear();
    }
    
    bool book(int start, int end) {
        auto it = scheduledEvent.lower_bound(start);
        
        if(it->first == start){
            ++ it;
        }
        
        if(it != scheduledEvent.end() && it->second < end){
            return false;
        }
        
        scheduledEvent[end] = start;
        
        return true;
    }
};
