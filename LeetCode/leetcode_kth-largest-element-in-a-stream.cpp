/*
*
* Tag: Heap (Data Structure)
* Time: O(nlgn)
* Space: O(k)
*/

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int sizeOfQueue;
public:
    KthLargest(int k, vector<int> nums) {
        sizeOfQueue = k;
        for(int num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        while(pq.size() > sizeOfQueue){
            pq.pop();
        }
        
        return pq.top();
    }
};
