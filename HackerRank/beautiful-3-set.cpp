/*
*
* From Codeforces
* Tag: Construction
* Time: O(n)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int n, k;

int main(){
	cin>>n;
	k = (2*n)/3;
	cout<<k+1<<endl;
	int y = 2*k-n;
	int x = n-2*y;
	for(int  i=0;i<=y;i++){
		cout<<i<<" "<<x+i<<" "<<n-x-2*i<<endl;
	}
	for(int  i=0;i<k-y;i++){
		cout<<y+i+1<<" "<<i<<" "<<n-y-1-2*i<<endl;
	}
	return 0;
}

