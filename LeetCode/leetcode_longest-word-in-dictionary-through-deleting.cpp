/*
*
* Tag: Sort
* Time: O(max(mlgm, n + m))
* Space: O(lgm)
*/
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        if(s.size() == 0 || d.size() == 0) {
            return ans;
        }
        
        sort(d.begin(), d.end(), cmp);
        for(int i = 0; i < d.size(); ++ i){
            if(checkLongestWord(s, d[i])){
                ans = d[i];
                break;
            }
        }
        return ans;
    }
    
private:
    bool checkLongestWord(string s, string t){
        int si = 0, ti = 0;
        while(si < s.size() && ti < t.size()){
            if(s[si] == t[ti])
                ++ ti;
            ++ si;
        }
        return ti >= t.size();
    }
    
    struct sortcmp {
      bool operator() (string a, string b) { 
          return a.size() == b.size() ? a < b : b.size() < a.size();
      }
    } cmp;
};
