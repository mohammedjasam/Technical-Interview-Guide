/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        // Write your code here
        vector<pair<int, double>> ans;
        if(!n)
            return ans;
        init(n);
        unordered_map<int,long long> predp, curdp;
        unordered_map<int,long long>::iterator it;
        for(int i = 1;i <= 6; ++ i)
            predp[i] = curdp[i] = 1;
        for(int i = 1; i < n; ++ i){
            curdp.clear();
            for(int j = 1; j <= 6; ++ j){
                for(it = predp.begin(); it != predp.end(); ++ it){
                    curdp[it->first + j] += it->second;
                }
            }
            predp = curdp;
        }
        ans.resize(curdp.size());
        int cnt = 0;
        for(int i = 1; i <= 6*n; ++ i){
            if(curdp.find(i) != curdp.end())
                ans[cnt ++] = make_pair(i, curdp[i]*1.0/prob);
        }
        return ans;
    }
private:
    void init(int n){
        double tmpprob = 6;
        prob = 1;
        while(n){
            if(n&1){
                prob *= tmpprob;
            }
            n >>= 1;
            tmpprob *= tmpprob;
        }
    }
private:
    double prob;
};
