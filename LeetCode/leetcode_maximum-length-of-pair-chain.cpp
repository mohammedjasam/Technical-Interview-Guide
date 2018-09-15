/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = 0;
        if(pairs.size() == 0){
            return ans;
        }
        
        sort(pairs.begin(), pairs.end(), cmp);
        
        int n = pairs.size();
        int curChainRightBound = pairs[0][1];
        ans = 1;
        for(int i = 1; i < n; ++ i){
            if(pairs[i][0] > curChainRightBound) {
                curChainRightBound = pairs[i][1];
                ++ ans;
            }
        }
        
        return ans;
    }
private:
    struct chainComparator{
        bool operator() (const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        }
    }cmp;
};
