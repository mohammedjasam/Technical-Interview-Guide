/*
*
* TODO O(n)
* Tag: Data Structure (Binary Search Tree)
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int ans = -1;
        if(k < 0){
            return ans;
        }
        
        set<int> positionOfBloomingFlowers;
        for(int i = 0; i < flowers.size(); ++ i){
            int pos = flowers[i];
            auto it = positionOfBloomingFlowers.upper_bound(pos);
            if(it != positionOfBloomingFlowers.end() && *it == pos + k + 1) {
                ans = i + 1;
                break;
            }
            
            positionOfBloomingFlowers.insert(pos);
            it = positionOfBloomingFlowers.find(pos);
            -- it;
            if(it != positionOfBloomingFlowers.end() && *it == pos - k - 1){
                ans = i + 1;
                break;
            }
        }
        
        return ans;
    }
};
