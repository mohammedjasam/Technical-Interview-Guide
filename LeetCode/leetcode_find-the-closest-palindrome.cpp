/*
*
* Tag: String && Math 
* Time: O(m)
* Space: O(1)
*/
class Solution {
public:
    string nearestPalindromic(string n) {
        if(n.size() == 0)
            return n;
        string ans = "";
        int len = n.size();
        set<long long> dict;
        dict.insert(long(pow(10, len)) + 1);
        dict.insert(long(pow(10, len - 1)) - 1);
        long prefix = stol(n.substr(0, (len + 1)/2));
        for(int i = -1; i <= 1; ++ i){
            string beg = to_string(prefix + i);
            string val = beg + string(beg.rbegin() + (len&1), beg.rend());
            dict.insert(stol(val));
        }
        long long dif, mindif = LLONG_MAX, num = stol(n), tmpans;
        dict.erase(num);
        for(auto tmp : dict){
            dif = abs(tmp - num);
            if(dif < mindif){
                mindif = dif;
                tmpans = tmp;
            }else if(dif == mindif){
                tmpans = min(tmpans, tmp);
            }
        }
        ans = to_string(tmpans);
        return ans;
    }
};
