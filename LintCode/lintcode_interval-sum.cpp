/*
*
* Tag: Data Structure (Binary Index Tree)
* Time: O(nlgn)
* Space: O(n)
*/
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */

    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<long long> ans;
        if(queries.size() == 0)
            return ans;
        ans.resize(queries.size());
        if(A.size() == 0){
            for(int i = 0; i < ans.size(); ++ i)
                ans[i] = 0;
            return ans;
        }
        indextree.resize(A.size() + 1);
        for(int i = 0; i < A.size(); ++ i)
            add(i + 1, A.size(), A[i]);
        for(int i = 0; i < ans.size(); ++ i)
            ans[i] = sum(queries[i].end + 1) - sum(queries[i].start);
        return ans;
    }
    
    void add(int start, int n, int val){
        for(int i = start; i <= n; i += lowbit(i))
            indextree[i] += val;
    }
    
    long long sum(int end){
        long long res = 0;
        for(int i = end; i > 0; i -= lowbit(i))
            res += indextree[i];
        return res;
    }
    
    int lowbit(int x){
        return x&-x;
    }
    
private:
    vector<long long> indextree;
};
