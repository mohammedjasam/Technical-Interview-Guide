/*
*
* Tag: Hash Map + Random
* Time: constructor: O(n) n is the length of black list; pick: O(1)
* Space: O(n)
*/
class Solution {
private:
    unordered_map<int, int> blackListNumOfWhiteListNum;
    int n;
    
public:
    Solution(int _n, vector<int> b) {
        n = _n;
        unordered_set<int> whiteList, blackList(b.begin(), b.end());
        for (int i = 0; i < n && whiteList.size() < b.size(); ++ i){
            if(blackList.count(i) != 0){
                continue;
            }
            
            whiteList.insert(i);
        }

        auto it = whiteList.begin();
        for (int x : b){
            if(it == whiteList.end()){
                it = whiteList.begin();
            }
            
            blackListNumOfWhiteListNum[x] = *it++;
        }
    }

    int pick() {
        int k = rand() % n;
	return blackListNumOfWhiteListNum.count(k) ? blackListNumOfWhiteListNum[k] : k;
    }
};
