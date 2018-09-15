/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
 /*
 *
 * Tag: DFS
 * Time: O(n)
 * Space: O(n)
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        idx = 0;
        ans.clear();
        if(!nestedList.size())
            return ;
        dfs(nestedList);
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        return ans[idx ++];
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
        return idx < ans.size();
    }
private:
    void dfs(const vector<NestedInteger> &nestedList){
        for(int i = 0; i < nestedList.size(); ++ i){
            if(nestedList[i].isInteger()){
                ans.push_back(nestedList[i].getInteger());
            }else{
                dfs(nestedList[i].getList());
            }
        }
    }
    
private:
    vector<int> ans;
    int idx;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
