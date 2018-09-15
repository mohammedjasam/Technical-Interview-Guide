/*
*
* Tag: Random
* Time: constructor: O(1); flip: O(1); reset: O(min(F,n_rows*n_cols)) F is the number of flips
* Space: O(min(F,n_rows*n_cols))
*/
class Solution {
private:
    unordered_map<int,int> V;
    int nr, nc, rem;

    //c++11 random integer generation
    mt19937 rng{random_device{}()};
    //uniform random integer in [0, bound]
    int randint(int bound) {
        uniform_int_distribution<int> uni(0, bound);
        return uni(rng);
    }
    
public:
    Solution(int n_rows, int n_cols) {
        nr = n_rows, nc = n_cols, rem = nr * nc;
    }

    vector<int> flip() {
        int r = randint(--rem);
        int x = V.count(r) ? V[r] : V[r] = r;
        V[r] = V.count(rem) ? V[rem] : V[rem] = rem;
        return {x / nc, x % nc};
    }

    void reset() {
        V.clear();
        rem = nr*nc;
    }
};
