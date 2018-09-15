/*
*
* Tag: Data Structure (Map)
* Time: O(lgn) for all four operations
* Space: O(n)
*/
class MaxStack {
private:
    map<int,vector<int>> stackPositionOfElements;
    map<int,int> elementsStack;
    int numOfElementsPushed;
public:
    /** initialize your data structure here. */
    MaxStack() {
        numOfElementsPushed = 0;
    }
    
    void push(int x) {
        elementsStack[numOfElementsPushed] = x;
        stackPositionOfElements[x].push_back(numOfElementsPushed);
        ++ numOfElementsPushed;
    }
    
    int pop() {
        auto it = elementsStack.rbegin();
        int ans = it->second;
        
        stackPositionOfElements[ans].pop_back();
        if(stackPositionOfElements[ans].size() == 0){
            stackPositionOfElements.erase(ans);
        }
        
        elementsStack.erase(it->first);
        return ans;
    }
    
    int top() {
        auto it = elementsStack.rbegin();
        return it->second;
    }
    
    int peekMax() {
        auto it = stackPositionOfElements.rbegin();
        return it->first;
    }
    
    int popMax() {
        auto it = stackPositionOfElements.rbegin();
        int ans = it->first;
        
        int stackPosition = stackPositionOfElements[ans].back();
        stackPositionOfElements[ans].pop_back();
        if(stackPositionOfElements[ans].size() == 0){
            stackPositionOfElements.erase(ans);
        }
        
        elementsStack.erase(stackPosition);
        return ans;
    }
};
