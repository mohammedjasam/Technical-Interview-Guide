/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/
class Solution {
public:
    /**
     * @param nums n non-negative integer array
     * @return a string
     */
    string minNumber(vector<int>& nums) {
        // Write your code here
        string ans = "";
        vector<string> arr(nums.size());
        if(!nums.size())
            return ans;
        int cnt = 0;
        for(int i = 0; i < arr.size(); ++ i){
            if(nums[i])
                arr[cnt ++] = to_string(nums[i]);
        }
        if(!cnt)
            arr[cnt ++] = to_string(0);
        sort(arr.begin(), arr.begin() + cnt, cmp);
        for(int i = 0; i < cnt; ++ i)
            ans += arr[i];
        return ans;
    }
    
private:
    struct sortcmp {
      bool operator() (string a, string b) { 
          return a+b < b+a;
      }
    } cmp;
};
