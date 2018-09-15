/*
*
* Tag: DFS
* Time: O(n^m)
* Space: O(m)
*/
class Solution {
public:
    /**
     * @param setList: The input set list
     * @return: the cartesian product of the set list
     */
    vector<vector<int>> getSet(vector<vector<int>> &setList) {
        vector<vector<int>> ans;
        if(setList.size() == 0)
            return ans;
        
        int totalVectors = 1;
        for(int i = 0; i < setList.size(); ++ i) {
            totalVectors *= setList[i].size();
        }
        ans.resize(totalVectors);
        
        vector<int> singleVector(setList.size());
        int curVector = 0;
        dfs(0, curVector, setList.size(), singleVector, ans, setList);
        
        return ans;
    }
private:
    void dfs(int curDep, int &curVector, int totDepth, vector<int> &singleVector, vector<vector<int>> &ans, vector<vector<int>> &setList) {
        if(curDep >= totDepth) {
            ans[curVector ++] = singleVector;
            return ;
        }
        
        for(int i = 0; i < setList[curDep].size(); ++ i){
            singleVector[curDep] = setList[curDep][i];
            dfs(curDep + 1, curVector, totDepth, singleVector, ans, setList);
        }
    }
};
