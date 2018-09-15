/*
*
* Tag: Data Structure (Min Heap)
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param numbers: the numbers
     * @return: the minimum cost
     */
    int mergeNumber(vector<int> &numbers) {
        if(numbers.size() == 1)
            return numbers[0];
        if(numbers.size() == 2)
            return numbers[0] + numbers[1];
            
        int minTotalEnergy = 0;
        priority_queue<int, vector<int>, greater<int> > minEnergyHeap(numbers.begin(), numbers.end());
        while(minEnergyHeap.size() > 1){
            int a = minEnergyHeap.top();
            minEnergyHeap.pop();
            int b = minEnergyHeap.top();
            minEnergyHeap.pop();
            int energy = a + b;
            minTotalEnergy += energy;
            minEnergyHeap.push(energy);
        }
        return minTotalEnergy;
    }
};
