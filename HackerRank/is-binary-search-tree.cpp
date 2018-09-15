/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
bool checkBST(Node* root) {
	bool ans = true;
  int maxval = -(1<<30);
  solve(root, maxval, ans);
  return ans;
}

void solve(Node* root, int &maxval, bool &ans){
    if(root->left)
        solve(root->left, maxval, ans);
    if(maxval >= root->data){
        ans = false;
        return ;
    }
    maxval = max(maxval, root->data);
    if(root->right)
        solve(root->right, maxval, ans);
}
