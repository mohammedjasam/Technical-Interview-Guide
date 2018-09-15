/*
*
* Tag: Binary Search
* Time Complexity: O(nlogn + Qn)
* Space Complexity: O(n)
*
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, q;
vector<long long> arr;
vector<long long> sum;

int BiSearchNeg(long long val,int l, int r){
    int idx = n - 1;
    if(val <= arr[l] || val >= arr[r]){
        return 0;
    }
    while(l <= r){
        int mid = (l + r)>>1;
        if(arr[mid] <= val){
            idx = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    while(arr[idx + 1] <= val) ++ idx;
    return idx + 1;
}

int BiSearchPos(long long val,int l, int r){
    int idx = n - 1;
    if(val >= arr[r] || val <= arr[l])
        return idx;
    while(l <= r){
        int mid = (l + r)>>1;
        if(arr[mid] <= val){
            idx = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    while(arr[idx + 1] <= val) ++ idx;
    return idx + 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    arr.resize(n);
    sum.resize(n);
    for(int i = 0; i < n; ++ i)
        scanf("%lld",&arr[i]);
    sort(arr.begin(), arr.end());
    
    
    long long neg_sum = 0, pos_sum = 0, ans = 0;
    int idx = 0;
    for(int i = 0; i < n; ++ i){
        if(i == 0)
            sum[i] = arr[i];
        else
            sum[i] = sum[i - 1] + arr[i];
        if(arr[i] < 0)
            neg_sum += arr[i];
        else{
            pos_sum += arr[i];
            if(i && arr[i] >= 0 && arr[i - 1] < 0)
                idx = i;
        }
    }
    
    
    scanf("%d",&q);
    ans = sum[n - 1];
    long long accumul_add = 0;
    while(q --){
        long long add_val;
        scanf("%lld",&add_val);
        accumul_add += add_val;
        if(accumul_add == 0){
            ans = abs(neg_sum) + pos_sum;
        }else if(accumul_add > 0){
            if(neg_sum == 0){
                ans = pos_sum + n*accumul_add;
            }else{
                int id = BiSearchNeg(-accumul_add, 0, idx - 1);
                long long neg_sum_1 = 0, neg_sum_2 = 0;
                if(id != 0){
                    neg_sum_1 = sum[id - 1] + accumul_add*id;
                    neg_sum_2 = sum[idx - 1] - sum[id - 1] + (idx - id)*accumul_add;
                }else{
                    neg_sum_2 = neg_sum + idx*accumul_add;
                }
                ans = pos_sum + (n - idx)*accumul_add + abs(neg_sum_1) + abs(neg_sum_2);
            }
        }else{
            if(pos_sum == 0){
                ans = abs(neg_sum + n*accumul_add);
            }else{
                int id = BiSearchPos(-accumul_add, idx, n - 1);
                long long pos_sum_1 = 0, pos_sum_2 = 0;
                if(id < n - 1){
                    pos_sum_1 = sum[id - 1] - sum[idx - 1] + (id - idx)*accumul_add;
                    pos_sum_2 = sum[n - 1] - sum[id - 1] + accumul_add*(n - id);
                }else
                    pos_sum_2 = pos_sum + (n - idx)*accumul_add;
                ans = abs(neg_sum) + abs((idx)*accumul_add) + abs(pos_sum_1) + abs(pos_sum_2);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

