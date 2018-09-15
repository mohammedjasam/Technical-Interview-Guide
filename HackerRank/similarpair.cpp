/*
*
* Tag: DFS
* Time: O(nlgn)
* Space: O(m)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
typedef long long llong;
 
vector<vector<int>> graph;
vector<int> deg; // in-degree
vector<int> tree;
int n, t;
 
// [left, right] is the segment to search
int query(int index, int left, int right, int begin, int end) {
    if (right < begin || left > end) return 0;
    if (left <= begin && right >= end) return tree[index];
    int mid = begin + (end - begin) / 2;
    return query(index * 2, left, right, begin, mid) + query(index * 2 + 1, left, right, mid + 1, end);
}
 
void update(int index, int node, int val, int begin, int end) {
    if (node < begin || node > end) {
        return;
    }
    if (begin <= node && node <= end) {
        tree[index] += val;   
    }
    if (begin == node && end == node) {
        return;
    }
    int mid = begin + (end - begin) / 2;
    update(index * 2, node, val, begin, mid);
    update(index * 2 + 1, node, val, mid + 1, end);
}
 
llong similarPairs(int root) {
    int l = max(1, root - t);
    int r = min(n, root + t);
    llong sim = query(1, l, r, 1, n);
    update(1, root, 1, 1, n);
    for (int i = 0; i < graph[root].size(); i++) {
        sim += similarPairs(graph[root][i]);
    }
    update(1, root, -1, 1, n);
    return sim;
}
 
int main() {
    cin >> n >> t;
    graph.resize(n + 1);
    deg.resize(n + 1);
    tree.resize(n * 4);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        deg[b]++;
    }
    int root = -1;
    for (int i = 1; i < deg.size(); i++) {
        if (deg[i] == 0) {
            root = i;
            break;
        }
    }
    llong result = similarPairs(root);
    cout << result << endl;
    return 0;
}
