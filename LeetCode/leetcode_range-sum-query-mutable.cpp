/*
*
* Tag: Data Structure (Binary Index Tree)
* Time: Update: O(lgn); SumRange: O(lgn)
* Space: O(n)
*/
class NumArray {
public:
    NumArray(vector<int> &nums) {
        if(!nums.size())
            return ;
        arr.resize(nums.size() + 1);
        bitree.resize(nums.size() + 1);
        for(int i = 0; i < bitree.size(); ++ i)
            bitree[i] = 0;
        for(int i = 0; i < nums.size(); ++ i){
            arr[i] = nums[i];
            add(i + 1, nums.size(), arr[i]);
        }
    }
    
    void update(int i, int val) {
        if(!arr.size())
            return ;
        if(arr[i] != val){
            int chg = val - arr[i];
            add(i + 1, arr.size() - 1, chg);
            arr[i] = val;
        }
    }

    int sumRange(int i, int j) {
        if(!arr.size())
            return 0;
        ++ j;
        int sum_i = 0, sum_j = 0;
        for(int k = i; k > 0; k -= lowbit(k))
            sum_i += bitree[k];
        for(int k = j; k > 0; k -= lowbit(k))
            sum_j += bitree[k];
        return sum_j - sum_i;
    }
    
    int lowbit(int x){
        return x&-x;
    }
private:
    void add(int start, int ends, int val){
        for(int i = start; i <= ends; i += lowbit(i))
            bitree[i] += val;
    }
    
private:
vector<int> arr;
vector<int> bitree;
};
