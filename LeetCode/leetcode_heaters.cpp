/*
*
* Tag: Binary Search
* Time: O(max(nlgn, n*lgm) where m is the maximum distance between heater and left and right most house)
* Space: O(1)
*/
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0;
        if(houses.size() == 0)
            return ans;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = INT_MAX, r = INT_MIN, n = houses.size(), m = heaters.size(), l_dis = 0, r_dis = 0, mid = 0;
        for(int i = 0; i < m; ++ i){
            l_dis = abs(heaters[i] - houses[0]);
            r_dis = abs(heaters[i] - houses[n - 1]);
            l = min(l, min(l_dis, r_dis));
            r = max(r, max(l_dis, r_dis));
        }
        ans = INT_MAX;
        while(l <= r){
            mid = (l + r)>>1;
            if(isValid(mid, houses, heaters)){
                ans = min(ans, mid);
                r = mid - 1;
            }else
                l = mid + 1;
        }
        return ans;
    }
private:
    bool isValid(int radius, vector<int>& houses, vector<int>& heaters){
        int n = houses.size(), m = heaters.size(), i = 0, j = 0;
        int l_bnd = heaters[j] - radius, r_bnd = heaters[j] + radius;
        while(i < n && j < m){
            if(houses[i] >= l_bnd && houses[i] <= r_bnd)
                ++ i;
            else{
                ++ j;
                l_bnd = heaters[j] - radius, r_bnd = heaters[j] + radius;
            }
        }
        return i >= n;
    }
};
