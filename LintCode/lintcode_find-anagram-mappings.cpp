/*
*
* Tag: Data Structure (Hash)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param A: lists A
     * @param B: lists B
     * @return: the index mapping
     */
    vector<int> anagramMappings(vector<int> &A, vector<int> &B) {
        vector<int> ans;
        if(A.size() == 0 || B.size() == 0)
            return ans;
        
        unordered_map<int,int> valueToIndexOfArrayB;
        for(int i = 0; i < B.size(); ++ i) {
            valueToIndexOfArrayB[B[i]] = i;
        }
        
        ans.resize(A.size());
        for(int i = 0; i < A.size(); ++ i) {
            ans[i] = valueToIndexOfArrayB[A[i]];
        }
        
        return ans;
    }
};
