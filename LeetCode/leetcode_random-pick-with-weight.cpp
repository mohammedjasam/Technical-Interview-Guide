/*
*
* Tag: Random + Binary Search
* Time: constructor: O(n); pick: O(lgn)
* Space: O(n)
*/
class Solution {
private:
    vector<int> psum;
    int tot = 0;
    //c++11 random integer generation
    mt19937 rng{random_device{}()};
    uniform_int_distribution<int> uni;
public:
    Solution(vector<int> w) {
        for (int x : w) {
            tot += x;
            psum.push_back(tot);
        }
        uni = uniform_int_distribution<int>{0, tot - 1};
    }

    int pickIndex() {
        int targ = uni(rng);

        int l = 0, r = psum.size() - 1;
        while (l != r) {
            int mid = (l + r) >> 1;
            if (targ >= psum[mid]) l = mid + 1;
            else r = mid;
        }
        
        return l;
    }
};
