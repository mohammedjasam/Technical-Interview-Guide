/*
*
* Tag: Implementation
* Time: O(nnm)
* Space: O(n)
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string peo[n];
    for(int i = 0; i < n; i ++)
        cin>>peo[i];
    int maxtp = -1, maxcnt = 0;
    for(int i = 0; i < n; i ++){
        for(int j = i + 1; j < n; j ++){
            int cnt = 0;
            for(int k = 0; k < m; k ++){
                if(peo[i][k] == '1' || peo[j][k] == '1')
                    cnt ++;
            }
            if(cnt > maxtp){
                maxtp = cnt;
                maxcnt = 1;
            }else if(cnt == maxtp){
                maxcnt ++;
            }
        }
    }
    cout<<maxtp<<endl;
    cout<<maxcnt<<endl;
    return 0;
}
