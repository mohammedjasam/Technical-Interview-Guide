/*
*
* Tag: Data Structure && Greedy
* Time: O((k + n)lgn)
* Space: O(n)
*/
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int ans = 0;
        if(Profits.size() == 0 || Capital.size() == 0)
            return ans;
        map<int,vector<int>> dict;
        map<int,vector<int>>::iterator it;
        priority_queue<int> pq;
        for(int i = 0; i < Profits.size(); ++ i){
            dict[Capital[i]].push_back(Profits[i]);
        }
        it = dict.begin();
        while(k > 0){
            for(;it != dict.end(); ++ it){
                if(it->first > W)
                    break;
                vector<int> tmp = it->second;
                for(int i = 0; i < tmp.size(); ++ i)
                    pq.push(tmp[i]);
            }
            if(!pq.empty()){
                W += pq.top();
                pq.pop();
                -- k;
            }else
                break;
        }
        ans = W;
        return ans;
    }
};
