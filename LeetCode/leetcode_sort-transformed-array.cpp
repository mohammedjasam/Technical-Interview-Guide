/*
*
* Tag: Math
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> ans(nums.size());
        if(!nums.size())
            return ans;
        int id = 0;
        if(!a){
            if(b < 0){
                for(int i = nums.size() - 1; i >= 0; -- i, ++ id)
                    ans[id] = nums[i]*b + c;
            }else{
                for(int i = 0; i < nums.size(); ++ i, ++ id)
                    ans[id] = nums[i]*b + c;
            }
        }else{
            int mid = 0, lid, rid, lval, rval;
            double tval = INT_MAX, cval = -1.0*(double)b/2.0/(double)a;
            for(int i = 0; i < nums.size(); ++ i){
                if(abs(nums[i] - cval) < tval){
                    tval = abs(nums[i] - cval);
                    mid = i;
                }
            }
            lid = mid;
            rid = mid + 1;
            if(a > 0){
                for(id = 0; id < nums.size(); ++ id){
                    if(lid >= 0)
                        lval = a*nums[lid]*nums[lid] + b*nums[lid] + c;
                    if(rid < nums.size())
                        rval = a*nums[rid]*nums[rid] + b*nums[rid] + c;
                    if(lid >= 0 && rid < nums.size()){
                        if(lval <= rval){
                            ans[id] = lval;
                            -- lid;
                        }else{
                            ans[id] = rval;
                            ++ rid;
                        }
                    }else if(lid >= 0){
                        ans[id] = lval;
                        -- lid;
                    }else if(rid < nums.size()){
                        ans[id] = rval;
                        rid ++;
                    }
                }
            }else{
                for(id = nums.size() - 1; id >= 0; -- id){
                    if(lid >= 0)
                        lval = a*nums[lid]*nums[lid] + b*nums[lid] + c;
                    if(rid < nums.size())
                        rval = a*nums[rid]*nums[rid] + b*nums[rid] + c;
                    if(lid >= 0 && rid < nums.size()){
                        if(lval >= rval){
                            ans[id] = lval;
                            -- lid;
                        }else{
                            ans[id] = rval;
                            ++ rid;
                        }
                    }else if(lid >= 0){
                        ans[id] = lval;
                        -- lid;
                    }else if(rid < nums.size()){
                        ans[id] = rval;
                        rid ++;
                    }
                }
            }
        }
        return ans;
    }
};
