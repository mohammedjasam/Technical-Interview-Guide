/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/
/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/
struct cmp{
    bool operator()(const node *a, const node *b){
        if(a->freq == b->freq)
            return a->data > b->data;
        return a->freq > b->freq;
    }
};

void dfs(node * root, string &code, unordered_map<string,char> &chk){

    if(!root->left && !root->right){
        chk[code] = root->data;
   //     cout<<chk[code]<<" "<<root->data<<endl;
        return ;
    }
    string new_code = "";
    if(root->left){
        new_code = code + "0";
        dfs(root->left, new_code, chk);
    }
    if(root->right){
        new_code = code + "1";
        dfs(root->right, new_code, chk);
    }
}


void decode_huff(node * root,string s)
{
 /*   unordered_map<char, int> dict;
    for(int i = 0; i < s.size(); ++ i){
        char k = s[i];
        if(dict.find(k) == dict.end())
            dict[k] = 1;
        else
            ++ dict[k];
    }
    priority_queue<node *, vector<node *>, cmp> pq;
    unordered_map<char, int>::iterator it = dict.begin();
    for(; it != dict.end(); ++ it){
        node *p = new node();
        p->data = it->first;
        p->freq = it->second;
        pq.push(p);
    }
    while(pq.size() != 1){
        node *left = pq.top();
        pq.pop();
        node *right = pq.top();
        pq.pop();
        node *new_root = new node();
        new_root->data = '\0';
        new_root->freq = left->freq + right->freq;
        pq.push(new_root);
    }
    root = pq.top();
    pq.pop(); */
    unordered_map<string, char> chk;
    string code = "";
    dfs(root, code, chk);
    string res = "", dec = "";
    int i = 0;
    
/*    unordered_map<string, char>::iterator it = chk.begin();
    for(; it != chk.end(); ++ it){
        cout<<it->first<<" - "<<it->second<<endl;
    } */
    
    for(; i < s.size(); ++ i){
        dec += s[i];
        if(chk.find(dec) != chk.end()){
            res += chk[dec];
            dec = "";
        }
    }
    cout<<res<<endl;
}
