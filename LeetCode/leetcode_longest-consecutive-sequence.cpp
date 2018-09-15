/*
*
* Tag: Data Structure (Union Find/Hash)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int n = num.size();
        if(n == 0){
            return 0;
        }
        
        int ans = INT_MIN;
        unordered_set<int> dict;
        dict.clear();
        for(int i = 0; i < n; ++ i){
            dict.insert(num[i]);
        }
        for(int i = 0; i < n; ++ i){
            if(dict.find(num[i]) != dict.end()){
                int len = 1, cur = num[i] - 1;
                while(dict.find(cur) != dict.end()){
                    dict.erase(cur);
                    len ++;
                    cur --;
                }
                cur = num[i] + 1;
                while(dict.find(cur) != dict.end()){
                    dict.erase(cur);
                    len ++;
                    cur ++;
                }
                ans = max(ans, len);
            }
        }
        
        return ans;
    }
};
