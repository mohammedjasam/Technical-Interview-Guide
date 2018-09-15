/*
*
* Tag: Hash
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0, v = 0;
        unordered_map<int,int> ab_dict, cd_dict;
        calTwoSum(A, B, ab_dict);
        calTwoSum(C, D, cd_dict);
        unordered_map<int,int>::iterator it;
        for(it = ab_dict.begin(); it != ab_dict.end(); ++ it){
            v = it->first;
            if(cd_dict.count(-v) > 0)
                ans += ab_dict[v]*cd_dict[-v]; 
        }
        return ans;
    }
private:
    void calTwoSum(vector<int>& A, vector<int>& B, unordered_map<int,int> &dict){
        for(int i = 0; i < A.size(); ++ i){
            for(int j = 0; j < B.size(); ++ j){
                ++ dict[A[i] + B[j]];
            }
        }
    }
};
