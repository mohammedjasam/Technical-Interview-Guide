/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        if(timeSeries.size() == 0)
            return res;
        timeSeries.push_back(INT_MAX);
        int t = 0, last_t = 0;
        for(int i = 0; i < timeSeries.size(); ++ i){
            if(t < timeSeries[i]){
                res += (t - last_t + 1);
                last_t = timeSeries[i];
            }
            t = max(t, timeSeries[i] + duration - 1);
        }
        return timeSeries[0] == 0?res:res - 1;
    }
};
