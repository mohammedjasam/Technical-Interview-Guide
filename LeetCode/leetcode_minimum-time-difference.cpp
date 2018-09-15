/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(lgn)
*/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int ans = INT_MAX;
        vector<int> minsArr(timePoints.size() + 1);
        for(int i = 0; i < timePoints.size(); ++ i){
            minsArr[i] = getMins(timePoints[i]);
        }
        sort(minsArr.begin(), minsArr.begin() + timePoints.size());
        minsArr[timePoints.size()] = minsArr[0] + getMins("24:00");
        for(int i = 1; i < minsArr.size(); ++ i){
            ans = min(ans, minsArr[i] - minsArr[i - 1]);
        }
        return ans;
    }
private:
    int getMins(string time){
        int res = 0;
        res = ((time[0]-'0')*10 + (time[1] - '0'))*60 + ((time[3]-'0')*10 + (time[4] - '0'));
        return res;
    }
};
