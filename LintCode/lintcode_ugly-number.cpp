class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        if(k == 1)
            return 3;
        if(k == 2)
            return 5;
        if(k == 3)
            return 7;
        priority_queue<long long, vector<long long>, greater<long long>> q;
        q.push(3);
        q.push(5);
        q.push(7);
        unordered_set<long long> st;
        st.insert(3);
        st.insert(5);
        st.insert(7);
        int cnt = 0;
        long long ans;
        while(!q.empty()){
            long long u = q.top();
            q.pop();
            ++ cnt;
            ans = u;
            if(cnt == k)
                break;
            if(st.find(3*u) == st.end()){
                q.push(3*u);
                st.insert(3*u);
            }
            if(st.find(5*u) == st.end()){
                q.push(5*u);
                st.insert(5*u);
            }
            if(st.find(7*u) == st.end()){
                q.push(7*u);
                st.insert(7*u);
            }
        }
        return ans;
    }
}
