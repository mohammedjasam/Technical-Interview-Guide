/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        if(height.size() == 0)
            return ans;
        stack<int> stk;
        int i = 0, idx = 0, tmpsum = 0;
        for(; i < height.size();){
            if(stk.empty() || height[i] <= height[stk.top()]){
                stk.push(i ++);
            }else{
                idx = stk.top();
                stk.pop();
                tmpsum = stk.empty()?0:((min(height[i], height[stk.top()]) - height[idx])*(i - 1 - stk.top()));
                ans += tmpsum;
            }
        }
        return ans;
    }
};


/*
* Tag: Brute force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n == 0) return 0;
        int ans = 0;
        for(int i = 0; i < n; i ++){
            if(!A[i]) continue;
            int sum = 0;
            for(int j = i + 1; j < n; j ++){
                if(A[j] >= A[i]) {
                    ans += sum;
                    i = j - 1;
                    break;
                }else if(j < n - 1){
                    sum += (A[i] - A[j]);
                }else if(j == n - 1){
                    ans += revers(i,j,A);
                    i = j;
                }
            }
        }
        return ans;
    }
    
    int revers(int sta,int ends,int A[]){
        int sum = 0;
        for(int i = ends - 1; i >= sta; i --){
            if(A[i] >= A[ends]){
                ends = i;
            }else{
                sum += (A[ends] - A[i]);
            }
        }
        return sum;
    }
};
