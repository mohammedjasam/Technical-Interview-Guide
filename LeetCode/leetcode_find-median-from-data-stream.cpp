/*
*
* Tag: Data Structure (Heap)
* Time: O(lgn)
* Space: O(n)
*/

class MedianFinder {
private:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int> > minheap;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if(maxheap.empty() || num <= maxheap.top()) {
            maxheap.push(num);
        } else {
            minheap.push(num);
        }
        
        if(maxheap.size() < minheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }else if(maxheap.size() >= minheap.size() + 2){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        double res;
        if(maxheap.size() == minheap.size()) {
            res = (maxheap.top() + minheap.top())/2.0;
        } else {
            res = (double)maxheap.top();
        }
        
        return res;
    }
};
