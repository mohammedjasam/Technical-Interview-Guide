/*
*
* Tag: Data Structure
* Time: O(1) for both push and pop operations
* Space: O(n)
*/

class FreqStack {
private:
    unordered_map<int,int> frequencyOfElement;
    unordered_map<int,stack<int>> stackOfElement;
    int maxFrequency;
public:
    FreqStack() {
        frequencyOfElement.clear();
        stackOfElement.clear();
        
        maxFrequency = 0;
    }
    
    void push(int x) {       
        ++ frequencyOfElement[x];
        stackOfElement[ frequencyOfElement[x] ].push(x);
        maxFrequency = max(maxFrequency, frequencyOfElement[x]);
    }
    
    int pop() {
        int ans = stackOfElement[maxFrequency].top();        
        stackOfElement[maxFrequency].pop();
        
        if(stackOfElement[maxFrequency].empty()){
            stackOfElement.erase(maxFrequency);
            -- maxFrequency;
        }       
        -- frequencyOfElement[ans];
        
        return ans;
    }
};
