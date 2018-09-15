/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        unordered_map<string,int> dict;
        for(int i = 0; i < list1.size(); ++ i)
            dict[list1[i]] = i;
        int sum = 0, ans_sum = INT_MAX;
        for(int i = 0; i < list2.size(); ++ i){
            if(dict.count(list2[i]) > 0){
                sum = dict[list2[i]] + i;
                if(sum < ans_sum) {
                    ans.clear();
                    ans.push_back(list2[i]);
                    ans_sum = sum;
                } else if(sum == ans_sum){
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};
