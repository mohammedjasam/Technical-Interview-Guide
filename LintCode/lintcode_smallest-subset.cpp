/*
*
* Tag: Implementation
* Time: O(n)
* Space: O()
*/
class Solution {
public:
    /**
     * @param arr:  an array of non-negative integers
     * @return: minimum number of elements
     */
    int minElements(vector<int> &arr) {
        if(arr.size() < 2)
            return arr.size();
        sort(arr.begin(), arr.end(), greater<int>());
        int sum = 0, minSubsetSum = 0, ans = 0;
        for(int i = 0; i < arr.size(); ++ i){
            sum += arr[i];
        }
        for(int i = 0; i < arr.size(); ++ i){
            ++ ans;
            minSubsetSum += arr[i];
            if(2*minSubsetSum > sum)
                break;
        }
        return ans;
    }
};
