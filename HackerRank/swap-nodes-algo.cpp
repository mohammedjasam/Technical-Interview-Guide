/*
*
* Tag: BFS
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
using namespace std;
unordered_map<int, pair<int, int> > tree;
unordered_map<int, unordered_set<int> > lv_tree;
int n, t, k, dep;

void BFS(){
    queue<int> q;
    q.push(1);
    unordered_set<int> tmp_set;
    tmp_set.insert(1);
    lv_tree[1] = tmp_set;
    int lv = 2;
    while(!q.empty()){
        queue<int> tmp_queue;
        unordered_set<int> tmp_set_lv;
        while(!q.empty()){
            int parent = q.front();
            q.pop();
            if(tree[parent].first != -1){
                tmp_set_lv.insert(tree[parent].first);
                tmp_queue.push(tree[parent].first);
            }
            if(tree[parent].second != -1){
                tmp_set_lv.insert(tree[parent].second);
                tmp_queue.push(tree[parent].second);
            }
        }
        lv_tree[lv] = tmp_set_lv;
        ++ lv;
        q = tmp_queue;
    }
    dep = lv;
}

void SwapChild(){
    for(int i = k; i < dep; i += k){
        unordered_set<int>::iterator it = lv_tree[i].begin();
        for(; it != lv_tree[i].end(); ++ it){
            int id = *it;
            swap(tree[id].first, tree[id].second);
          /* tree[id].first = tree[id].first^tree[id].second;
            tree[id].second = tree[id].first^tree[id].second;
            tree[id].first = tree[id].first^tree[id].second; */
        }
    }
}

void dfs(int u){
    if(tree[u].first != -1)
        dfs(tree[u].first);
    printf("%d ",u);
    if(tree[u].second != -1)
        dfs(tree[u].second);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    for(int i = 1; i <= n; ++ i){
        int a, b;
        scanf("%d%d",&a,&b);
        tree[i] = make_pair(a, b);
    }
    BFS();
    scanf("%d",&t);
    for(int i = 0; i < t; ++ i){
        scanf("%d",&k);
        SwapChild();
        dfs(1);
        puts("");
    }
    return 0;
}
