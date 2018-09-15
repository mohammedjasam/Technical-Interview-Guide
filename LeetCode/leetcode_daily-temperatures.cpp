/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>&  temperatures) {
        vector<int> ans(temperatures.size(), 0);
        if(temperatures.size() == 0){
            return ans;
        }
        
        stack<int> stk;
        for(int i = 0; i < temperatures.size(); ++ i){
            updateDatesForWarmerTemperature(i, temperatures, stk, ans);
            stk.push( i );
        }
        
        return ans;
    }
private:
    void updateDatesForWarmerTemperature(int curIndex, vector<int>& temperatures, stack<int>& stk, vector<int> &ans){
        while(!stk.empty()){
            int lastIndex = stk.top();
            if( temperatures[lastIndex] < temperatures[curIndex] ) {
                stk.pop();
                ans[lastIndex] = curIndex - lastIndex;
            } else {
                break;
            }
        }
    }
};
