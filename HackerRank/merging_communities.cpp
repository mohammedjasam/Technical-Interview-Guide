/*
*
* Tag: Union Find (Data Structure)
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<int> fa;
char op[3];
unordered_map<int,int> dict;
int n, q;

void init(){
    fa.resize(n + 1);
    for(int i = 0; i <= n; ++ i){
        fa[i] = -1;
        dict[i] = 1;
    }
}

int find(int u){
    int s = u;
    for(s = u; fa[s] > 0; s = fa[s]) ;
    while(s != u){
        int tmp = fa[u];
        fa[u] = s;
        u = tmp;
    }
    return s;
}

void unionSet(int a, int b){
    int r1 = find(a), r2 = find(b);
    int tmp = fa[r1] + fa[r2];
    if(r1 <= r2){
        dict[r1] += dict[r2];
        dict[r2] = 0;
        fa[r1] = tmp;
        fa[r2] = r1;
    }else{
        dict[r2] += dict[r1];
        dict[r1] = 0;
        fa[r2] = tmp;
        fa[r1] = r2;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d",&n,&q);
    init();
    while(q --){
        scanf("%s",op);
        int u, v;
        if(op[0] == 'M'){
          scanf("%d%d",&u,&v);
          if(find(u) != find(v)){
              unionSet(u, v);
          }  
        }else{
            scanf("%d",&u);
            int id = find(u);
            printf("%d\n",dict[id]);   
        }
    }
    return 0;
}
