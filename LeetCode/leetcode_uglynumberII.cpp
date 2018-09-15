/*
* Tag: Data Structure
* Sub Tag: Heap and Hash Set
* Time: O(nlogn) where n is the given number
* Space: O(n)
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        int cnt = 0, ans;
        if(n == 1)
            return 1;
        priority_queue<int, vector<int>, greater<int> > min_pq;
        unordered_set<int> st;
        min_pq.push(1);
        st.insert(1);
        while(cnt < n){
            ans = min_pq.top();
            min_pq.pop();
            ++ cnt;
            if(cnt == n)
                break;
            for(int i = 0; i < 3; ++ i){
                if(st.find(ans*mul_val[i]) == st.end() && ((long long)ans)*mul_val[i] <= INT_MAX){
                    min_pq.push(ans*mul_val[i]);
                    st.insert(ans*mul_val[i]);
                }
            }
        }
        return ans;
    }
private:
    vector<int> mul_val={2,3,5};
};
