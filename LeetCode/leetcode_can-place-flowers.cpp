/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0)
            return true;
        if(flowerbed.size() == 0)
            return false;
        int cnt = 0;
        for(int i = 0; i < flowerbed.size(); ++ i){
            if(flowerbed[i] == 0 && canPlaceFlower(i, flowerbed)) {
                flowerbed[i] = 1;
                ++ cnt;
            }
            if(cnt >= n)
                return true;
        }
        return false;
    }
private:
    inline bool canPlaceFlower(int pos, vector<int>& flowerbed) {
        bool valid_left = false, valid_right = false;
        valid_left = (pos == 0 || (pos >= 1  && flowerbed[pos - 1] == 0) );
        valid_right = (pos == flowerbed.size() - 1 || (pos + 1 < flowerbed.size() && flowerbed[pos + 1] == 0) );
        return valid_left && valid_right;
    }
};
