/*
*
* Tag: Data Structure
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        vector<int> ans(k);
        priority_queue<int, vector<int> > maxHeap(nums.begin(), nums.end());
        
        for(int i = 0; i < k && i < nums.size(); ++ i) {
            ans[i] = maxHeap.top();
            maxHeap.pop();
        }
        
        return ans;
    }
};
