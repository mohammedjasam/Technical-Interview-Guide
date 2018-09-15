/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets <= 1)
            return 0;
        long long t = (minutesToTest - 1)/minutesToDie + 1;
        return log(buckets - 1)/log(t + 1) + 1;
    }
};
