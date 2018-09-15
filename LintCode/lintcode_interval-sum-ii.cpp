/*
*
* Tag: Data Structure (Binary Index Tree)
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    /* you may need to use some attributes here */
    

    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        // write your code here
        indextree.resize(A.size() + 1);
        arr.resize(A.size() + 1);
        for(int i = 0; i < A.size(); ++ i)
            arr[i + 1] = A[i];
        for(int i = 0; i < A.size(); ++ i)
            add(i + 1, A.size(), A[i]);
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        long long ans = 0;
        if(start == end)
            return arr[start + 1];
        ans = sum(end + 1) - sum(start);
        return ans;
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        // write your code here
        int oldval = arr[index + 1];
        int val = value - oldval;
        arr[index + 1] = value;
        add(index + 1, arr.size() - 1, val);
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
    vector<int> arr;
};

