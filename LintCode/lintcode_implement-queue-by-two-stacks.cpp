/*
*
* Tag: Implementation
* Time: push: O(1); pop: O(1); top: O(n)
* Space: O(n)
*/
class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
        while(!stack1.empty())
            stack1.pop();
        while(!stack2.empty())
            stack2.pop();
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        if(!stack2.empty()){
            int res = stack2.top();
            stack2.pop();
            return res;
        }else{
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
            return pop();
        }
    }

    int top() {
        // write your code here
        if(!stack2.empty()){
            int res = stack2.top();
            return res;
        }else{
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
            return top();
        }
    }
};
