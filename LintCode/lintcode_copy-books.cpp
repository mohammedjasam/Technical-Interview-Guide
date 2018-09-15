/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int ans = 0, n = pages.size();
        if(k >= pages.size()){
            for(int i = 0; i < n; ++ i)
                ans = max(ans, pages[i]);
            return ans;
        }
        
        int sum = 0;
        for(int i = 0; i < n; ++ i){
            sum += pages[i];
        }
        
        int l = sum/k, r = sum;
        while(l <= r){
            int mid = (l + r)>>1;
            if(check(pages, mid, k)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        
        return ans;
    }
    
    bool check(vector<int> &pages, int val, int k){
        int sum = 0, n = pages.size(), cnt = 0;
        for(int i = 0; i < n; ++ i){
            if(sum + pages[i] > val){
                sum = 0;
                ++ cnt;
            }
            sum += pages[i];
        }
        
        return cnt < k && sum <= val;
    }
    
};
