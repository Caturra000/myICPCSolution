#pragma GCC diagnostic error "-std=c++11"
#include<ext/pb_ds/priority_queue.hpp>
#include<bits/stdc++.h>
#define unordered_map map
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
const int MAXN = 1e5+11;
const int INF  = 0x3f3f3f3f;
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN],tot;
void init(int n){
    memset(head,-1,(n+2)*sizeof(int));
    tot=0;
} 
void add(int u,int v){
    to[tot]=v;
    nxt[tot]=head[u];
    head[u]=tot++;
}
int dep[MAXN];
void dfs(int u,int fa,int d){
    dep[u]=d;
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u,d+1);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("stdin.txt","r",stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,u,v;
    while(cin>>n){
        init(n);
        for(int i=1;i<n;i++){
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        dfs(1,-1,1);
        double ans=0;
        for(int i=1;i<=n;i++) ans+=1.0/dep[i];
        cout<<fixed<<setprecision(12)<<ans<<endl;
    }
    return 0;
}