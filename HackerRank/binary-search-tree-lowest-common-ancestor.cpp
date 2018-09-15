/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/
node * lefts, * rights;
void dfs(node * root, unordered_map<node *, node *> &fa, unordered_map<node *, int> &hight, int v, int &cnt, bool isleft){
    if(root->data == v){
        if(isleft)
            lefts = root;
        else
            rights = root;
        ++ cnt;
        if(cnt == 1)
            return ;
    }
    if(root->data > v){
        if(!root->left)
            return ;
        fa[root->left] = root;
        hight[root->left] = hight[root] + 1;
        dfs(root->left, fa, hight, v, cnt, isleft);
        if(cnt == 1)
            return ;
    }else{
        if(!root->right)
            return ;
        fa[root->right] = root;
        hight[root->right] = hight[root] + 1;
        dfs(root->right, fa, hight, v, cnt, isleft);
        if(cnt == 1)
            return ;
    }
}

node * lca(node * root, int v1, int v2){
    unordered_map<node *, node *> fa;
    unordered_map<node *, int> hight;
    int cnt = 0;
    fa[root] = NULL;
    hight[root] = 1;
    dfs(root, fa, hight, v1,cnt, true);
    dfs(root, fa, hight, v2, cnt, false);
    if(lefts == rights)
        return lefts;
    if(hight[lefts] < hight[rights])
        swap(lefts, rights);
    while(hight[lefts] > hight[rights]) lefts = fa[lefts];
    while(fa[lefts] != fa[rights]){
        lefts = fa[lefts];
        rights = fa[rights];
    } 
    if(lefts == rights)
        return lefts;
    return fa[lefts];
}
