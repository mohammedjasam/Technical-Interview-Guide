/*
*
* Tag: Data Structure (Binary Indexed Tree)
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        long long ans = 0;
        if(!A.size())
            return ans;
        int n = A.size();
        vector<int> B(n);
        for(int i = 0; i < n; ++ i)
            B[i] = A[i];
        sort(B.begin(), B.end());
        indextree.resize(n + 1);
        factval.resize(n + 1);
        uniq_cnt.resize(n + 1);
        
        uniq_cnt[n] = uniq_cnt[n - 1] = 1;
        st.insert(A[n - 1]);
        for(int i = n - 2; i >= 0; -- i){
            if(st.find(A[i]) != st.end())
                uniq_cnt[i] = uniq_cnt[i + 1];
            else{
                uniq_cnt[i] = uniq_cnt[i + 1] + 1;
                st.insert(A[i]);
            }
        }
        
        long long val = 1;
        for(long long i = 0; i < n; ++ i){
            add(i + 1, B.size(), 1);
            dict[B[i]] = i + 1;
            if(i){
                val *= i;
                factval[i] = val;
            }
        }
        
        for(long long i = 0; i < n; ++ i){
            int idx = dict[A[i]];
            long long rank = sum(idx - 1);
            ans += rank*factval[uniq_cnt[i + 1]];
            add(idx, n, -1);
        }
        
        return ans + 1;
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
vector<int> indextree;
vector<long long> factval;
unordered_map<int, int> dict;
unordered_set<int> st;
vector<int> uniq_cnt;     
};
