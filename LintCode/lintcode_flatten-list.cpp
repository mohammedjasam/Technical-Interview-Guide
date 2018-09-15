/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        // Write your code here
        vector<int> ans;
        dfs(nestedList, ans);
        return ans;
    }
private:
    void dfs(const vector<NestedInteger> &nestedList, vector<int> &ans){
        for(int i = 0; i < nestedList.size(); ++ i){
            if(nestedList[i].isInteger())
                ans.push_back(nestedList[i].getInteger());
            else
                dfs(nestedList[i].getList(), ans);
        }
    }
};
