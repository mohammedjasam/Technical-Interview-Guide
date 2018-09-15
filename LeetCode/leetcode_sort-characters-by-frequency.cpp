/*
*
* Tag: Data Structure
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> dict;
        string ans = s;
        if(!s.size())
            return ans;
        for(int i = 0; i < s.size(); ++ i)
            ++ dict[s[i]];
        map<int,unordered_set<char>> buckets;
        for(unordered_map<char,int>::iterator it = dict.begin(); it != dict.end(); ++ it){
            buckets[it->second].insert(it->first);
        }
        int cnt = 0, idx = 0;
        for(map<int,unordered_set<char> >::reverse_iterator rit = buckets.rbegin(); rit != buckets.rend(); ++ rit){
            for(unordered_set<char>::iterator it = rit->second.begin(); it != rit->second.end(); ++ it){
                cnt = rit->first;
                while(cnt --){
                    ans[idx ++] = *it;
                }
            }
        }
        return ans;
    }
};

/*
*
* Tag: Sort
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> dict;
        vector<vector<char>> buckets(s.size() + 1, vector<char>());
        string ans = s;
        if(!s.size())
            return ans;
        for(int i = 0; i < s.size(); ++ i)
            ++ dict[s[i]];
        for(unordered_map<char,int>::iterator it = dict.begin(); it != dict.end(); ++ it){
            buckets[it->second].push_back(it->first);
        }
        int num = 0;
        for(int i = s.size(), cnt = 0; i > 0; -- i){
            if(cnt >= s.size())
                break;
            for(int j = 0; j < buckets[i].size(); ++ j){
                num = i;
                while(num --){
                    ans[cnt ++] = buckets[i][j];
                }
            }
        }
        return ans;
    }
};
