/*
*
* Tag: Heap
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    string rearrangeString(string str, int k) {
        string ans(str.size(), 0);
        if(!str.size())
            return ans;
        if(!k)
            return str;
        
        unordered_map<char,int> dict;
        priority_queue<pair<int,char>> pq;
        int len = (int)str.size();
        for(int i = 0; i < str.size(); ++ i)
            ++ dict[str[i]];
        for(unordered_map<char,int>::iterator it = dict.begin(); it != dict.end(); ++ it)
            pq.push(make_pair(it->second, it->first));
        vector<pair<int,char>> tmp(pq.size());
        int tot = 0;
        while(!pq.empty()){
            int cnt = min(k, len), id = 0;
            for(int i = 0; i < cnt; ++ i){
                if(pq.empty())
                    return "";
                pair<int,char> val = pq.top();
                pq.pop();
                ans[tot ++ ] = val.second;
                if(--val.first > 0)
                    tmp[id ++] = val;
                -- len;
            }
            for(int i = 0; i < id; ++ i)
                pq.push(tmp[i]);
        }
        
        return ans;
    }
};
