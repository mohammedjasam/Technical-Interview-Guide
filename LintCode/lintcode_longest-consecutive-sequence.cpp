/*
*
* Tag: Data Structure (Hash)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        int ans = INT_MIN;
        int n = num.size();
        set<int> dict;
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
