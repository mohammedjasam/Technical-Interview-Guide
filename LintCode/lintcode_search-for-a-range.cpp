/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> ans(2);
        ans[0] = ans[1] = -1;
        if(!A.size())
            return ans;
        bsearch(A, target, ans);
        return ans;
    }
    
    void bsearch(vector<int> &A, int target, vector<int> &ans){
        int l = 0, r = A.size() - 1;
        if(A[0] == target)
            ans[0] = 0;
        if(A[r] == target)
            ans[1] = r;
        if(ans[0] != -1 && ans[1] != -1)
            return ;
        int id = -1;
        while(l <= r){
            int mid = (l + r)>>1;
            if(A[mid] == target){
                id = mid;
                break;
            }else if(A[mid] < target){
                l = mid + 1;
            }else
                r = mid - 1;
        }
        if(id == -1)
            return ;
        for(int i = id; i >= 0; -- i){
            if(A[i] < target)
                break;
            ans[0] = i;
        }
        for(int i = id; i < A.size(); ++ i){
            if(A[i] > target)
                break;
            ans[1] = i;
        }
    }
};
