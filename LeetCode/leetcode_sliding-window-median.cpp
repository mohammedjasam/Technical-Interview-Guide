/*
*
* Tag: Data Structure
* Time: O(nlgk)
* Space: O(k)
*/
class Solution {
private:
    map<int,int> lwset, upset;
    int lwcnt, upcnt;
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        if(nums.size() == 0 || k == 0)
            return ans;
        if(k == 1){
            ans.resize(nums.size());
            for(int i = 0; i < nums.size(); ++ i)
                ans[i] = (double)nums[i];
            return ans;
        }
        int id = 0;
        lwset.clear();
        upset.clear();
        lwcnt = upcnt = 0;
        vector<int> tmp(k);
        for(int i = 0; i < k; ++ i)
            tmp[i] = nums[i];
        ans.resize(nums.size() - k + 1);
        sort(tmp.begin(), tmp.end());
        if(k%2 == 0)
            ans[id ++] = ((double)tmp[k/2] + (double)tmp[k/2 - 1])/2.0;
        else
            ans[id ++] = (double)tmp[k/2];
        if(k < nums.size()){
            for(int i = 0; i < k; ++ i){
                if(i < (k + 1)/2){
                    ++ lwset[tmp[i]];
                    ++ lwcnt;
                }else{
                    ++ upset[tmp[i]];
                    ++ upcnt;
                }
            }

            for(int i = k; i < nums.size(); ++ i){
                if(lwset.find(nums[i - k]) != lwset.end() ){
                    -- lwset[nums[i - k]];
                    -- lwcnt;
                    if(lwset[nums[i - k]] == 0)
                        lwset.erase(nums[i - k]);
                }else{
                    -- upset[nums[i - k]];
                    -- upcnt;
                    if(upset[nums[i - k]] == 0)
                        upset.erase(nums[i - k]);
                }
                ans[id ++] = getMid(nums[i], k);
            }
        }
        return ans;
    }
private:

    double getMid(int v, int k){
        double res = 0;
   //     multiset<int>::iterator it = upset.begin();
        int mid_v = 0;
        if(lwcnt == 0){
            ++ lwcnt;
            ++ lwset[v];
        }else{
            mid_v = lwset.rbegin()->first;
            if(mid_v >= v){
                ++ lwset[v];
                ++ lwcnt;
            }else{
                ++ upset[v];
                ++ upcnt;
            }
        }
        if(k%2 == 0){
            while(lwcnt > upcnt){
                mid_v = lwset.rbegin()->first;
                -- lwset[mid_v];
                -- lwcnt;
                if(lwset[mid_v] == 0)
                    lwset.erase(mid_v);
                ++ upset[mid_v];
                ++ upcnt;
            }
            while(upcnt > lwcnt){
                mid_v = upset.begin()->first;
                -- upset[mid_v];
                -- upcnt;
                if(upset[mid_v] == 0)
                    upset.erase(mid_v);
                ++ lwset[mid_v];
                ++ lwcnt;
            }
            res = ((double)lwset.rbegin()->first + (double)upset.begin()->first)/2.0;
        }else{
            while(lwcnt - upcnt > 1){
                mid_v = lwset.rbegin()->first;
                -- lwset[mid_v];
                -- lwcnt;
                if(lwset[mid_v] == 0)
                    lwset.erase(mid_v);
                ++ upset[mid_v];
                ++ upcnt;
            }
            while(upcnt >= lwcnt){
                mid_v = upset.begin()->first;
                -- upset[mid_v];
                -- upcnt;
                if(upset[mid_v] == 0)
                    upset.erase(mid_v);
                ++ lwset[mid_v];
                ++ lwcnt;
            }
            res = (double)(lwset.rbegin()->first);
        }
        return res;
    }

};
