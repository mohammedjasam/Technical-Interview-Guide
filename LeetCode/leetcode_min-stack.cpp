/*
*
* Tag: Data Structure
* Time: O(1)
* Space: O(n)
*/
class MinStack {
public:
    void push(int x) {
        all_val.push(x);
        if(min_val.empty() || x <= min_val.top())
            min_val.push(x);
    }

    void pop() {
        int val = all_val.top();
        all_val.pop();
        if(val == min_val.top())
            min_val.pop();
    }

    int top() {
        return all_val.top();
    }

    int getMin() {
        return min_val.top();
    }
private:
    stack<int> all_val, min_val;
};
