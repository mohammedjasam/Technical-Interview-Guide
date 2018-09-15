/*
*
* Tag: Binary Search
* Time: O(nlgm) where m is the difference between smallest integer and largest integer in the file. n is the number of integers in the file.
* Space: O(1)
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <climits>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
using namespace std;

class IntegerFinder {
public:
    double findMedianOf(vector<int> &nums){
        int numOfNums = 0, leftBound = INT_MAX, rightBound = INT_MIN;
        for(int i = 0; i < nums.size(); ++ i){
            ++ numOfNums;
            leftBound = min(leftBound, nums[i]);
            rightBound = max(rightBound, nums[i]);
        }
                
        if(numOfNums&1 != 0){
            return getKthSmallestNumberOf(nums, (numOfNums + 1)>>1, leftBound, rightBound);
        } else {
            return (getKthSmallestNumberOf(nums, numOfNums>>1, leftBound, rightBound) + getKthSmallestNumberOf(nums, (numOfNums>>1) + 1 , leftBound, rightBound) )/2.0;
        }
    }

private:
    int getKthSmallestNumberOf(vector<int> &nums, int k, int leftBound, int rightBound){
        while(leftBound < rightBound){
            int mid = leftBound + (rightBound - leftBound)/2;
            int count = findNumOfNoLargerNumbers(nums, mid);
            if(count < k){
                leftBound = mid + 1;
            } else {
                rightBound = mid;
            }
        }
        
        return leftBound;
    }
    
    int findNumOfNoLargerNumbers(vector<int> &nums, int target){
        int count = 0;
        for(int num : nums){
            count += num <= target ? 1 : 0;
        }
        
        return count;
    }
};

int main() {
    IntegerFinder intfinder;
    vector<int> nums1 = {3,2,1};
    double ans = intfinder.findMedianOf(nums1);
    cout<<ans<<endl;
    
    vector<int> nums2 = {2,2,2,2,2,2,2,2,1};
    ans = intfinder.findMedianOf(nums2);
    cout<<ans<<endl;
    
    vector<int> nums3 = {2,2,2,2,2,2,2,2,1,3};
    ans = intfinder.findMedianOf(nums3);
    cout<<ans<<endl;
    
    vector<int> nums4 = {1,2,3,4,5,6,7,8};
    ans = intfinder.findMedianOf(nums4);
    cout<<ans<<endl;
    
    vector<int> nums5 = {9,5,6,7,2,3,4,8,1};
    ans = intfinder.findMedianOf(nums5);
    cout<<ans<<endl;
    
    vector<int> nums6 = {-100, 99, 3, 0, 5, 7, 11, 66, -33};
    ans = intfinder.findMedianOf(nums6);
    cout<<ans<<endl;
    
    vector<int> nums7 = {4, -100, 99, 3, 0, 5, 7, 11, 66, -33};
    ans = intfinder.findMedianOf(nums7);
    cout<<ans<<endl;
    return 0;
}
