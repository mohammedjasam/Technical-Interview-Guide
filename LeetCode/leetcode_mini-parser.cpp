/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
*/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s.empty())
            return NestedInteger();
        if(s.front() != '[')
            return NestedInteger(stoi(s));
        for(int i = 0, j = 0; j < s.size(); ++ j){
            if(s[j] == '['){
                pstk.push(NestedInteger());
                i = j + 1;
            }else if(s[j] == ']'){
                if(s[j - 1] >= '0' && s[j - 1] <= '9')
                    pstk.top().add(NestedInteger(stoi(s.substr(i, j- i))));
                if(pstk.size() > 1){
                    NestedInteger cur = pstk.top();
                    pstk.pop();
                    pstk.top().add(cur);
                }
                i = j + 1;
            }else if(s[j] == ','){
                if(s[j - 1] >= '0' && s[j - 1] <= '9')
                    pstk.top().add(NestedInteger(stoi(s.substr(i, j-i))));
                i = j + 1;
            }
        }
        return pstk.top();
    }
private:
    stack<NestedInteger> pstk;
};
