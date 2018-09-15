/*
* Tag: Trie Tree
*
*
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int M = 1000010;
const int N = 15;
int n;
int tree[M][N];
int end_ch[M];
int sz;
vector<string> vec_str; 

void insert(string str){
    int u = 0, len = str.size();
    for(int i = 0; i < len; ++ i){
        int idx = str[i] - 'a';
        if(!tree[u][idx]){
            memset(tree[sz], 0, sizeof(tree[sz]));
            tree[u][idx] = sz ++;
        }
        u = tree[u][idx];
    }
    end_ch[u] = -1;
}


bool find(string str){
    int len = str.size(), u = 0;
    for(int i = 0; i < len; ++ i){
        int idx = str[i] - 'a';
        if(!tree[u][idx]){
            return end_ch[u] == -1;
        }
        u = tree[u][idx];
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    vec_str.resize(n);
    memset(tree[0], 0, sizeof(tree[0]));
    memset(end_ch, 0, sizeof(end_ch));
    sz = 1;
    for(int i = 0; i < n; ++ i)
        cin>>vec_str[i];

    bool isfind = false;
    for(int i = 0; i < n; ++ i){
        if(i){
            if(find(vec_str[i])){
                isfind = true;
                cout<<"BAD SET"<<endl;
                cout<<vec_str[i]<<endl;
                break;
            }
        }
        insert(vec_str[i]);
    }
    if(!isfind)
        cout<<"GOOD SET"<<endl;
    return 0;
}
