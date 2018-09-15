/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int totgas = 0, totcost = 0;
        if(gas.size() != cost.size() || !gas.size())
            return -1;
        if(!cost.size())
            return 0;
        double rate = -9999999999.9;
        int idx = 0, n = gas.size();
        for(int i = 0; i < n; ++ i){
            totgas += gas[i];
            totcost += cost[i];
            double val = (double)gas[i]/(double)cost[i];
            if(rate < val){
                rate = val;
                idx = i;
            }
        }
        return totgas >= totcost?idx:-1;
    }
};
