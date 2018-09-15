/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int ans = 0;
        if(machines.size() == 0)
            return ans;
        int sum = 0, n = machines.size();
        for(int i = 0; i < n; ++ i)
            sum += machines[i];
        if(sum%n != 0)
            return -1;
        int avg = sum/n, res = 0, tmpsum = 0;
        for(int i = 0; i < n; ++ i){
            tmpsum += machines[i] - avg;
            ans = max(ans, max(machines[i] - avg, abs(tmpsum)));
        }
        return ans;
    }
};
