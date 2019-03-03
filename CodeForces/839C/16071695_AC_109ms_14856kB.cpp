#pragma GCC diagnostic error "-std=c++11"
#include<ext/pb_ds/priority_queue.hpp>
#include<bits/stdc++.h>
#define unordered_map map
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
const int MAXN = 2e5+11;
const int INF  = 0x3f3f3f3f;
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN],tot;
ll cost[MAXN<<1];
void init(int n){
    memset(head,-1,(n+2)*sizeof(int));
    tot=0;
} 
void add(int u,int v,ll w=0){
    to[tot]=v;
    cost[tot]=w;
    nxt[tot]=head[u];
    head[u]=tot++;
}
int N;
double dp[MAXN];
double DP(int u,int fa){
    if(dp[u]>-23333) return dp[u];
    int cnt=0;
    double res=0;
    for(int i=head[u];~i;i=nxt[i]){
        if(to[i]==fa) continue;
        res+=1.0+DP(to[i],u);
        cnt++;
    }
    return dp[u]=fabs(res)<1e-6?0:res/cnt;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("stdin.txt","r",stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m,u,v; ll w;
    while(cin>>n){
        init(N=n);
        for(int i=1;i<=n;i++) dp[i]=-INF;
        for(int i=1;i<=n-1;i++){
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        cout<<fixed<<setprecision(12)<<DP(1,-1)<<endl;
    }
    return 0;
}