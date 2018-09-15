/*
*
* Tag: Data Structure (Hash)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size());
        if(A.size() == 0){
            return ans;
        }
        
        unordered_map<int,int> indexOfElementsInArrayB;
        for(int i = 0; i < B.size(); ++ i){
            indexOfElementsInArrayB[B[i]] = i;
        }
        
        for(int i = 0; i < A.size(); ++ i){
            ans[i] = indexOfElementsInArrayB[A[i]];
        }
        
        return ans;
    }
};
