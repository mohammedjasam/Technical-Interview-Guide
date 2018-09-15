/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int ans = 0;
        if(!nestedList.size())
            return ans;
        maxdep = 0;
        getDepth(nestedList, 1);
        getWeightSum(nestedList, 0, ans);
        return ans;
    }
private:
    void getDepth(vector<NestedInteger>& nestedList, int dep){
        maxdep = max(maxdep, dep);
        for(int i = 0; i < nestedList.size(); ++ i){
            if(!nestedList[i].isInteger()){
                getDepth(nestedList[i].getList(), dep + 1);
            }
        }
    }
    
    void getWeightSum(vector<NestedInteger>& nestedList, int dep, int &ans){
        int sum = 0;
        for(int i = 0; i < nestedList.size(); ++ i){
            if(!nestedList[i].isInteger()){
                getWeightSum(nestedList[i].getList(), dep + 1, ans);
            }else{
                sum += nestedList[i].getInteger();
            }
        }
        ans += (maxdep - dep)*sum;
    }
private:
    int maxdep;
};
