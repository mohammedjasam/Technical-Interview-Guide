/*
*
* Tag: Order Statistics
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans(k);
        if(!nums.size() || !k)
            return ans;
        unordered_map<int,int> dict;
        for(int i = 0; i < nums.size(); ++ i)
            ++ dict[nums[i]];
        vector<pair<int,int>> arr(dict.size());
        int i = 0;
        for(unordered_map<int,int>::iterator it = dict.begin(); it != dict.end(); ++ it, ++ i){
            arr[i] = make_pair(it->first, it->second);
        }
        -- k;
        kthlargest(arr, ans, k);
        return ans;
    }
private:
    void kthlargest(vector<pair<int,int>> &arr, vector<int> &ans, int k){
        int n = arr.size() - 1, start = 0, end = arr.size() - 1, tpos;
        while(1){
            pair<int,int> pivot = arr[end];
            tpos = start - 1;
            for(int i = start; i < end; ++ i){
                if(arr[i].second < pivot.second){
                    swap(arr[i], arr[++ tpos]);
                }
            }
            swap(arr[++ tpos], arr[end]);
            if(tpos == n - k){
                break;
            }else if(tpos > n - k){
                end = tpos - 1;
            }else{
                start = tpos + 1;
            }
        }
        int id = 0;
        for(int i = n; i >= tpos; -- i, ++ id)
            ans[id] = arr[i].first;
    }
};
