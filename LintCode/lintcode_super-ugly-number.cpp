/*
*
* Tag: Heap
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Write your code here
        if(n <= 1)
            return n;
        if(!primes.size())
            return 0;
        int k = primes.size();
        vector<int> indx(k, 0);
        vector<int> ans(n);
        map<long long, int> heap;
        ans[0] = 1;
        for(int i = 0; i < k; ++ i){
            heap[primes[i]] = i;
        }
        int id = 1;
        while(id < n){
            auto cur = *(heap.begin());
            heap.erase(heap.begin());
            if(cur.first != ans[id - 1])
                ans[id ++] = cur.first;
            indx[cur.second] ++;
            while(heap.count( primes[cur.second]*ans[indx[cur.second]] )){
                indx[cur.second] ++;
            }
            heap[primes[cur.second]*ans[indx[cur.second]]] = cur.second;
        }
        
        return ans[n - 1];
    }
};
