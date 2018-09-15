/*
*
* Tag: Data Structure (Stack)
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        if(!nums.size())
            return 0;
        vector<int> stack(nums.size() + 5);
        int n = nums.size(),tmp,top=0;
		stack[top]=-1;
		for(int i=0;i<n;i++){
			tmp = nums[i];
			if(tmp>=stack[top]){
				stack[++top]=tmp;
			}
			else{
				int low=1,high=top;
				while(low<=high){
					int mid=(low+high)>>1;
					if(stack[mid]<tmp) low=mid+1;
					else high=mid-1;
				}
				//Equality is taken into account
				while(stack[low] <= tmp)
					low ++;
				if(stack[low] > tmp)
					low --;
				//Equality is not taken into account
				while(stack[low]>=tmp)
					low--;
				if(stack[low] < tmp)
					low ++;
				stack[low]=tmp;
			}
		}
		return top;
    }
};

