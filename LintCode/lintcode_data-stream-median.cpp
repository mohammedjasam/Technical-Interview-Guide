/*
*
* Tag: Data Structure (Heap)
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        priority_queue<int> lessavg;
        priority_queue<int, vector<int>, greater<int> > largeravg;
        vector<int> ans;
        if(!nums.size())
            return ans;
        int lesscnt = 0, largercnt = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++ i){
            if(!i){
                ++ lesscnt;
                lessavg.push(nums[i]);
                ans.push_back(nums[i]);
            }else{
                int val = lessavg.top();
                if(nums[i] <= val){
                    lessavg.push(nums[i]);
                    ++ lesscnt;
                }else{
                    largeravg.push(nums[i]);
                    ++ largercnt;
                }
                if(abs(lesscnt - largercnt) <= 1){
                    if(largercnt > lesscnt){
                        val = largeravg.top();
                        largeravg.pop();
                        lessavg.push(val);
                        -- largercnt;
                        ++ lesscnt;
                    }
                }else{
                    if(lesscnt - largercnt > 1){
                        val = lessavg.top();
                        lessavg.pop();
                        largeravg.push(val);
                        ++ largercnt;
                        -- lesscnt;
                    }else{
                        val = largeravg.top();
                        largeravg.pop();
                        lessavg.push(val);
                        -- largercnt;
                        ++ lesscnt;
                    }
                }
                ans.push_back(lessavg.top());
            }
        }
        return ans;
    }
};
