/*
*
* Tag: DFS + Memorization
* Time: O(n1*n2*..nM*m) where ni is the number of ith item needed and m is the number of offers
* Space: O(n1*n2*..nM*n)
*/
class Solution {
private:
    unordered_map<string, int> state;
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        state.clear();
        return shopping(price, special, needs);
    }

private:
    int shopping(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        string hashKeyOfNeeds = getNeedsStateHashKeyString(needs);
        if(state.count(hashKeyOfNeeds) != 0){
            return state[hashKeyOfNeeds];
        }
        
        int res = totalPriceWithoutSpecialOffers(price, needs);
        for(vector<int> offer : special){
            vector<int> curNeeds(needs.begin(), needs.end());
            bool canUseOffer = true;
            for(int i = 0; i < curNeeds.size(); ++ i){
                curNeeds[i] -= offer[i];
                if(curNeeds[i] < 0) {
                    canUseOffer = false;
                    break;
                }
            }
            
            if(canUseOffer){
                res = min(res, offer[offer.size() - 1] + shopping(price, special, curNeeds));
            }
        }
        state[hashKeyOfNeeds] = res;
        
        return res;
    }
    
    int totalPriceWithoutSpecialOffers(vector<int>& price, vector<int>& needs){
        int totalPrice = 0;
        for(int i = 0; i < price.size(); ++ i){
            totalPrice += price[i]*needs[i];
        }
        
        return totalPrice;
    }
    
    string getNeedsStateHashKeyString(vector<int>& needs){
        string hashKey = "";
        for(int need : needs){
            hashKey += to_string(need)+",";
        }
        
        return hashKey;
    }
};
