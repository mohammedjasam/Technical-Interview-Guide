/*
*
* Tag: Greedy
* Time: O(n^2)
* Space: O(lgn)
*/
class Solution {
struct cmp{
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return b.first < a.first || (a.first == b.first && a.second < b.second);
    }
}cmpobj;
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> ans;
        if(people.size() == 0)
            return ans;
        sort(people.begin(), people.end(), cmpobj);
        for(int i = 0; i < people.size(); ++ i)
            ans.insert(ans.begin() + people[i].second, people[i]);
        return ans;
    }

};
