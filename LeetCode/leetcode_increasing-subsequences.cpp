/*
*
* Tag: DFS
* Time: O(2^n)
* Space: O(2^n)
*/
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> tmp;
        set<vector<int>> st;
        dfs(nums, tmp, st, 0, 0);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
private:
    void dfs(vector<int> &nums, vector<int> &tmp, set<vector<int>> &st, int dep, int idx){
        if(dep >= 2){
            st.insert(tmp);
        }
        
        for(int i = idx; i < nums.size(); ++ i){
            if(tmp.size() == 0 || nums[i] >= tmp[tmp.size() - 1]){
                tmp.push_back(nums[i]);
                dfs(nums, tmp, st, dep + 1, i + 1);
                tmp.pop_back();
            }
        }
    }
};



class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 0)
            return ans;
        unordered_set<string> st;
        st.clear();
        string mask = "";
        for(int i = 0; i < nums.size() - 1; ++ i){
            mask = to_string(nums[i])+",";
            dfs(1, i, i + 1, ans, mask, nums, st);
        }
        return ans;
    }
private:
    void dfs(int dep, int lid, int start, vector<vector<int>> &ans, string &mask, vector<int> &nums, unordered_set<string> &st){
        if(dep >= 2){
            if(st.find(mask) == st.end()){
                vector<int> tmp;
                string::iterator it = mask.begin(), nxt;
                int val = 0;
                while(it != mask.end()){
                    nxt = find(it, mask.end(), ',');
                    val = stoi(string(it, nxt));
                    tmp.push_back(val);
                    it = nxt + 1;
                }
                ans.push_back(tmp);
                st.insert(mask);
            }
        }
        if(start >= nums.size())
            return ;
        string nxtmask = "";
        for(int i = start; i < nums.size(); ++ i){
            if(nums[i] >= nums[lid]){
                nxtmask = mask + to_string(nums[i]) + ",";
                dfs(dep + 1, i, i + 1, ans, nxtmask, nums, st);
            }
        }
    }
};
