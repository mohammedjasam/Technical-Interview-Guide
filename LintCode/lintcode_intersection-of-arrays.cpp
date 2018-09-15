/*
*
* Tag: 
* Time: O(n)
* Space: O(m) (shortest size of arrays)
*/
class Solution {
public:
    /**
     * @param arrs: the arrays
     * @return: the number of the intersection of the arrays
     */
    int intersectionOfArrays(vector<vector<int>> &arrs) {
        int ans = 0;
        if(arrs.size() == 0)
            return ans;
        
        int idx = getIndexOfShortestArr(arrs);
        unordered_map<int,int> intersectElements = getInitIntersectElements(arrs, idx);
        
        int n = arrs.size();
        for(int i = 0; i < n; ++ i){
            if(i == idx)
                continue;
            for(int j = 0; j < arrs[i].size(); ++ j){
                if(intersectElements.count(arrs[i][j]) == 0)
                    continue;
                ++ intersectElements[arrs[i][j]];
                if(isElementInAllArrays(arrs[i][j], intersectElements, n))
                    ++ ans;
            }
        }
            
        return ans;
    }
    
private:
    int getIndexOfShortestArr(vector<vector<int>> &arrs){
        int idx = 0, curMinSize = arrs[0].size();
        for(int i = 1; i < arrs.size(); ++ i){
            if(curMinSize > arrs[i].size()){
                curMinSize = arrs[i].size();
                idx = i;
            }
        }
        return idx;
    }
    
    unordered_map<int,int> getInitIntersectElements(vector<vector<int>> &arrs, int idx) {
        unordered_map<int,int> res;
        
        for(int i = 0; i < arrs[idx].size(); ++ i)
            res[arrs[idx][i]] = 1;
        
        return res;
        
    }
    
    bool isElementInAllArrays(int element, unordered_map<int,int> &intersectElements, int numOfArrays){
        return intersectElements[element] == numOfArrays;
    }
};
