/*
*
* Tag: Data Structure (Binary Index Tree)
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
private:
    unordered_map<int,int> dict;
    vector<int> bittree;
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        if(!nums.size()) {
            return ans;
        }
        
        vector<int> tmp = nums;
        int n = nums.size();
        sort(tmp.begin(), tmp.end());
        
        int cnt = 1;
        for(int i = 0; i < tmp.size(); ++ i){
            if(dict.find(tmp[i]) == dict.end())
                dict[tmp[i]] = cnt ++;
        }
        
        ans.resize(nums.size());
        bittree.resize(nums.size() + 1);
        for(int i = nums.size() - 1; i >= 0; -- i){
            ans[i] = add(dict[nums[i]] - 1);
            update(1, dict[nums[i]], n);
        }
        
        return ans;
    }
private:
    int lowbit(int x){
        return x&-x;
    }
    
    int add(int sta){
        int res = 0;
        for(int i = sta; i > 0; i -= lowbit(i)) {
            res += bittree[i];
        }
        
        return res;
    }
    
    void update(int val, int sta, int bnd){
        for(int i = sta; i <= bnd; i += lowbit(i)) {
            bittree[i] += val;
        }
    }

};
