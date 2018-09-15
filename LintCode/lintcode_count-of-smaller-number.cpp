/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        vector<int> ans;
        if(!queries.size())
            return ans;
        ans.resize(queries.size());
        if(!A.size())
            return ans;
        sort(A.begin(), A.end());
        for(int i = 0; i < queries.size(); ++ i){
            int val = queries[i];
            ans[i] = bsearch(A, val);
        }
        return ans;
    }
private:
    int bsearch(vector<int> A, int val){
        int l = 0, r = A.size() - 1;
        int res = 0;
        while(l <= r){
            int mid = (l + r)>>1;
            if(A[mid] < val){
                res = mid + 1;
                l = mid + 1;
            }else if(A[mid] == val){
                res = mid;
                r = mid - 1;
            }else
                r = mid - 1;
        }
        return res;
    }
};
