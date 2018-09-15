#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const ll MAXN = 510;
ll n,m,k;
ll a[MAXN][2],b[MAXN][2];
struct node{
    ll u,v;
    ll dis;
    bool operator<(const node& r)const{
        return dis<r.dis;
 }
}data[MAXN*MAXN];
ll uN,vN;  
ll g[MAXN][MAXN]; 
ll linker[MAXN];
bool used[MAXN];
bool dfs(ll u)
{
    ll v;
    for(v=0;v<vN;v++)
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }    
        }  
    return false;  
}    
ll hungary()
{
    ll res=0;
    ll u;
    memset(linker,-1,sizeof(linker));
    for(u=0;u<uN;u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u))  res++;
    } 
    return res;   
}     
ll calc(ll x){
    memset(g,0,sizeof(g));
    for(ll i=0;i<=x;i++){
        ll x = data[i].u;
        ll y = data[i].v;
        g[x][y] = 1;
    }
    return hungary();
}
ll solve(){
    ll cnt = 0;
    uN = n;
    vN = m;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            data[cnt].u=i;
            data[cnt].v=j;
            data[cnt].dis = (a[i][0]-b[j][0])*(a[i][0]-b[j][0])+(a[i][1]-b[j][1])*(a[i][1]-b[j][1]);
            cnt++;
        }
        
    }
    sort(data,data+cnt);
    ll lb=-1,ub=cnt;
    while(ub-lb>1){
        ll mid = (ub+lb)/2;
        if(calc(mid)>=k){
            ub = mid;
        }else{
            lb = mid;
        }
    }
    return data[ub].dis;
}
int main() {
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(ll i=0;i<n;i++)cin>>a[i][0]>>a[i][1];
    for(ll i=0;i<m;i++)cin>>b[i][0]>>b[i][1];
    ll ans = solve();
    cout<<ans<<endl;
    return 0;
}
