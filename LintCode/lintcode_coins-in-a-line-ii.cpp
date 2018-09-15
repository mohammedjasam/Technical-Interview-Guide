/*
*
* Tag: Game
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int sum1 = 0, sum2 = 0;
        bool turn = true;
        int n = values.size();
        for(int i = 0; i < n;){
            int &sum = turn?sum1:sum2;
            sum += values[i ++];
            if(i < n && (i + 1 >= n || (values[i] >= values[i + 1]))){
                sum += values[i ++];
            }
            turn = !turn;
        }
        return sum1 > sum2;
    }
};
