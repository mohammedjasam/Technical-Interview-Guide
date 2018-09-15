/*
*
* Tag: DFS
* Time: O(n^3)
* Space: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
string fst, s;
bool canfind;

bool cmpval(string pre, string cur){
    if(pre.size() > cur.size() || (pre.size() == cur.size() && pre > cur ))
        return false;
    string addOne = "";
    int c = 0, one = 1;
    for(int i = pre.size() - 1; i >= 0; -- i){
        int v = (pre[i] - '0') + one + c;
        addOne = ((char)((v%10) + '0')) + addOne;
        c = v/10;
        one = 0;
    }
    if(c == 1)
        addOne = '1' + addOne;
    return addOne == cur;
}

void dfs(string preval, int idx, int num){
    if(idx >= s.size()){
        if(preval != "0" && num >= 2)
            canfind = true;
        return ;
    }
    string cur = "", val = "";
    for(int i = idx; i < s.size(); ++ i){
        cur += s[i];
        if(i < s.size() && s[i + 1] == '0')
            continue;
        val = cur;
        if(preval == "0"){
            dfs(val, i + 1, num + 1);
        }else if(cmpval(preval, val))
            dfs(val, i + 1, num + 1);
        if(canfind){
            if(preval == "0")
                fst = cur;
            return ;
        }
    }
}

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        cin >> s;
        if(s[0] == '0' || s.size() == 1){
            puts("NO");
            continue;
        }
        fst = "";
        canfind = false;
        dfs("0",0,0);
        if(canfind)
            cout<<"YES"<<" "<<fst<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
