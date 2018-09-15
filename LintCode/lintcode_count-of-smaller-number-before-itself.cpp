/*
*
* Tag: Data Structure (Binary Index Tree)
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        vector<int> ans;
        if(!A.size())
            return ans;
        indextree.resize(10010);
        ans.resize(A.size());
        int n = A.size();
        for(int i = 0; i < n; ++ i){
            ans[i] = query(A[i]);
            add(A[i] + 1);
        }
        return ans;
    }
    
    int lowbit(int x){
        return x&-x;
    }
    
    int query(int end){
        int res = 0;
        for(int i = end; i > 0; i -= lowbit(i))
            res += indextree[i];
        return res;
    }
    
    void add(int start){
        for(int i = start; i <= 10005; i += lowbit(i))
            ++ indextree[i];
    }
private:
    vector<int> indextree;
};
