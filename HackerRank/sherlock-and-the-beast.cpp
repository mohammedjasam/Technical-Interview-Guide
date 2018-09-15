/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void init(vector<int> &threefac, vector<int> &fivefac, vector<pair<int,int> > &comb_sum, vector<bool> &vis){
  	threefac.push_back(0);
  	int len = 3;
  	while(len <= 100100){
      threefac.push_back(len);
      len += 3;
    }
  	len = 5;
  	fivefac.push_back(0);
  	while(len <= 100100){
      fivefac.push_back(len);
      len += 5;
    }
  	for(int i = 0; i < 100100; i ++){
      pair<int,int> tmp_pair;
      comb_sum.push_back(tmp_pair);
    }
  	for(int i = threefac.size() - 1; i >= 0; i --){
      	for(int j = fivefac.size() - 1; j >= 0; j --){
          	int idx = threefac[i] + fivefac[j];
          	if(idx > 100010 || vis[idx] == true)
              continue;
          	pair<int,int> tmp_comb;
          	tmp_comb.first = threefac[i];
          	tmp_comb.second = fivefac[j];
          	comb_sum[idx] = tmp_comb;
          	vis[idx] = true;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  	vector<int> threefac, fivefac;
  	vector<pair<int,int> > comb_sum;
  	vector<bool> vis(100100, false);
  	init(threefac, fivefac, comb_sum, vis);
  	int T;
  	cin>>T;
  	while(T --){
      int idx;
      cin>>idx;
      if(!vis[idx])
        cout<<"-1"<<endl;
      else{
        int num_five = comb_sum[idx].first;
        int num_three = comb_sum[idx].second;
        for(int i = 0; i < num_five; i ++)
          cout<<"5";
        for(int i = 0; i < num_three; i ++)
          cout<<"3";
        cout<<endl;
      }
    }
    return 0;
}
