/*
*
* Tag: Data Structure (Binary Search Tree)
* Time: Add: O(m); Leave: O(lgm) where m is the number of students
* Space: O(m)
*/
class ExamRoom {
private:
    int n;
    set<int> seats;
public:
    ExamRoom(int _n) {
        n = _n;
    }
    
    int seat() {
        if(seats.empty()){
            seats.insert(0);
            return 0;
        }
        
        int maxDistance = max(*(seats.begin()), n - 1 - *(seats.rbegin()));
        auto fastIt = seats.begin();
        ++ fastIt;
        for(auto it = seats.begin(); fastIt != seats.end(); ++ it, ++ fastIt){
            maxDistance = max(maxDistance, (*(fastIt) - *it)/2);
        }
        
        if(maxDistance == *(seats.begin())){
            seats.insert(0);
            return 0;
        }
        
        fastIt = seats.begin();
        ++ fastIt;
        for(auto it = seats.begin(); fastIt != seats.end(); ++ it, ++ fastIt){
            if((*(fastIt) - *it)/2 == maxDistance){
                int pos = (*(fastIt) + *it)/2;
                seats.insert(pos);
                return pos;
            }
        }
        seats.insert(n - 1);
        
        return n - 1;
    }
    
    void leave(int p) {
        seats.erase(p);
    }
};


/*
*
* Tag: Data Structure (Binary Search Tree)
* Time: Add: O(m); Leave: O(m) where m is the number of students
* Space: O(m)
*/
class ExamRoom {
private:
    int n;
    list<int> seats;
public:
    ExamRoom(int _n) {
        n = _n;
    }
    
    int seat() {
        if(seats.empty()){
            seats.push_back(0);
            return 0;
        }
        
        int maxDistance = max(*(seats.begin()), n - 1 - seats.back());
        auto fastIt = seats.begin();
        ++ fastIt;
        for(auto it = seats.begin(); fastIt != seats.end(); ++ it, ++ fastIt){
            maxDistance = max(maxDistance, (*(fastIt) - *it)/2);
        }
        
        if(maxDistance == *(seats.begin())){
            seats.push_front(0);
            return 0;
        }
        
        fastIt = seats.begin();
        ++ fastIt;
        for(auto it = seats.begin(); fastIt != seats.end(); ++ it, ++ fastIt){
            if((*(fastIt) - *it)/2 == maxDistance){
                int pos = (*(fastIt) + *it)/2;
                seats.insert(fastIt, pos);
                return pos;
            }
        }
        seats.push_back(n - 1);
        
        return n - 1;
    }
    
    void leave(int p) {
        for(auto it = seats.begin(); it != seats.end(); ++ it){
            if(*it == p){
                seats.erase(it);
                return ;
            }
        }
        
        return ;
    }
};
