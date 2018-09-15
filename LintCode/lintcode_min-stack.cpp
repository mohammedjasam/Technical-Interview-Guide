/*
*
* Tag: Data Structure
* Time: O(n) (worst) for push and pop operation
        O(1) for min operation
* Space: O(n)
*/
class MinStack {
public:
    MinStack() {
        // do initialization if necessary
        while(!all_val.empty())
            all_val.pop();
        while(!min_val.empty())
            min_val.pop();
    }

    void push(int number) {
        // write your code here
        all_val.push(number);
        if(min_val.empty() || number <= min_val.top())
            min_val.push(number);
    }

    int pop() {
        // write your code here
        int val = all_val.top();
        all_val.pop();
        if(val == min_val.top())
            min_val.pop();
        return val;
    }

    int min() {
        // write your code here
        return min_val.top();
    }
private:
    stack<int> all_val, min_val;
};

