/*
*
* Tag: Data Structure (Binary Index Tree)
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // Write your code here
        if(!A.size())
            return 0;
        long long res = 0;
        idxmp.clear();
        vector<int> B(A);
        sort(B.begin(), B.end());
        int idx = 1, n = A.size();
        tree.resize(n + 1);
        for(int i = 0; i < B.size(); ++ i){
            if(idxmp.find(B[i]) == idxmp.end()){
                idxmp[B[i]] = idx ++;
            }
        }
        for(int i = n - 1; i >= 0; -- i){
            res += sum(idxmp[A[i]]);
            update(idxmp[A[i]], n);
        }
        return res;
    }
private:
    int lowbit(int x){
        return x&-x;
    }
    
    long long sum(int idx){
        long long res = 0;
        for(int i = idx - 1; i > 0; i -= lowbit(i)){
            res += tree[i];
        }
        return res;
    }
    
    void update(int idx, int n){
        for(int i = idx; i <= n; i += lowbit(i))
            ++ tree[i];
    }
private:
    vector<long long> tree;
    unordered_map<int,int> idxmp;
};
