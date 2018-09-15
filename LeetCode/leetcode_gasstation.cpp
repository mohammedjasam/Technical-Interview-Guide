/*
*
* Algorithm: Greedy
* Time Complexity: O(n)
* Memory Complexity: O(n)
*
*/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        double rate = -9999999.99;
        int ind = 0, totgas = 0, totcost = 0;
        for(int i = 0; i < gas.size(); i ++){
            totgas += gas[i];
            totcost += cost[i];
            if(rate < (double)gas[i]/(double)cost[i]){
                rate = (double)gas[i]/(double)cost[i];
                ind = i;
            }
        }
        return totgas >= totcost? ind : -1;
    }
};
