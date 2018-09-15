/*
*
* Tag: Hash & Bit Manipulation
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        init();
        vector<string> ans;
        unordered_set<string>::iterator hidx, midx;
        string h = "", m = "";
        for(int i = 0; i <= num; ++ i){
            if(hh.find(i) == hh.end() || mm.find(num - i) == mm.end())
                continue;
            for(hidx = hh[i].begin(); hidx != hh[i].end(); ++ hidx){
                h = *hidx;
                for(midx = mm[num - i].begin(); midx != mm[num - i].end(); ++ midx){
                    m = *midx;
                    ans.push_back(h+":"+m);
                }
            }
        }
        return ans;
    }
    
private:
    
    void init(){
        hh.clear();
        mm.clear();
        int cnt = 0, v = 0;
        string str_v = "";
        for(int i = 0; i < 12; ++ i){
            cnt = 0;
            v = i;
            while(v){
                if(v&1)
                    ++ cnt;
                v >>= 1;
            }
            hh[cnt].insert(to_string(i));
        }
        for(int i = 0; i < 60; ++ i){
            cnt = 0;
            v = i;
            while(v){
                if(v&1)
                    ++ cnt;
                v >>= 1;
            }
            str_v = to_string(i);
            if(i < 10)
                str_v = "0"+str_v;
            mm[cnt].insert(str_v);
        }
    }
    
private:
    unordered_map<int, unordered_set<string>> hh, mm;
};
