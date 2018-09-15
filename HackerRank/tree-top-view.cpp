/*
*
* Tag: DFS + BFS
* Time: O(n)
* Space: O(n)
*/
/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void top_view(node * root){
    stack<int> st;
    queue<int> q;
    node *tmp = root;
    while(tmp){
        st.push(tmp->data);
        tmp = tmp->left;
    }
    bool isfirst = true;
    while(!st.empty()){
        if(!isfirst)
            printf(" ");
        printf("%d",st.top());
        st.pop();
        isfirst = false;
    }
    tmp = root->right;
    while(tmp){
        q.push(tmp->data);
        tmp = tmp->right;
    }
    while(!q.empty()){
        if(!isfirst)
            printf(" ");
        printf("%d",q.front());
        q.pop();
        isfirst = false;
    }
}
