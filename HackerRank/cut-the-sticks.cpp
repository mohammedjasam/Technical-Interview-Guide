/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<set>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> ary, cnt;
    set<int> dic;
    ary.resize(n);
    dic.clear();
    int len = n;
    for(int i = 0; i < n; i ++)
        scanf("%d",&ary[i]);
    sort(ary.begin(),ary.end());
    for(int i = 0; i < n; i ++){
        if(dic.find(ary[i]) == dic.end()){
            dic.insert(ary[i]);
            cnt.push_back(1);
        }else{
            cnt[cnt.size() - 1] ++;
        }
    }
    printf("%d\n",n);
    for(int i = 0; i < cnt.size() - 1; i ++){
        printf("%d\n",len - cnt[i]);
        len -= cnt[i];
    }
    return 0;
}
