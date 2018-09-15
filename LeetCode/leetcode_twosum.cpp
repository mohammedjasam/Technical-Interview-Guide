class Solution {

public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans(2);
        unordered_map<int, int> dic, dup_dic;
        int n = numbers.size();
        for(int i = 0; i < n; ++ i){
            if(dic.find(numbers[i]) == dic.end())
                dic[numbers[i]] = i + 1;
            else
                dup_dic[numbers[i]] = i + 1;
        }
        for(int i = 0; i < n; ++ i){
            int dif = target - numbers[i];
            if(dif == numbers[i]){
                if(dup_dic.find(dif) != dup_dic.end()){
                    ans[0] = i + 1;
                    ans[1] = dup_dic[dif];
                    break;
                }
            }else{
                if(dic.find(dif) != dic.end()){
                    ans[0] = i + 1;
                    ans[1] = dic[dif];
                    break;
                }
            }
        }
        return ans;
    }
};
