/*
*
* Tag: Binary Search Tree
* Time: O(n^2)
* Space: O(n)
*/
class MyCalendarThree {
private:
    map<int,int> timeScheduler;
public:
    MyCalendarThree() {
        timeScheduler.clear();
    }
    
    int book(int start, int end) {
        ++ timeScheduler[start];
        -- timeScheduler[end];
        
        int ans = 0, delta = 0;
        for(auto it = timeScheduler.begin(); it != timeScheduler.end(); ++ it){
            delta += it->second;
            ans = max(ans, delta);
        }
        
        return ans;
    }
};
