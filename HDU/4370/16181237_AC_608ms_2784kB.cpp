#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#include<unordered_map>
#define rep(i,j,k) for( int i=j;i<=k;i++)
#define rrep(i,j,k) for( int i=j;i>=k;i--)
#define erep(i,u) for( int i=head[u];~i;i=nxt[i])
#define fastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define println(x) print(x),print('\n')
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pr = pair<ll,ll>;
const int MAXN = 555+11;
const int INF  = 0x3f3f3f3f;
const double EPS = 1e-7;
const ll MOD = 1000000007;
ll d[MAXN][MAXN],dis[MAXN];
bool vis[MAXN];
int n;
void spfa(int st){
    queue<int> que;
    vis[st]=0,dis[st]=INF;
    rep(i,1,n) if(i!=st){
        dis[i]=d[st][i];
        vis[i]=1;
        que.push(i);
    }
    while(!que.empty()){
        int u=que.front(); que.pop(); vis[u]=0;
        for(int v=1;v<=n;v++){
            if(dis[v]>dis[u]+d[u][v]){
                dis[v]=dis[u]+d[u][v];
                if(!vis[v]){
                    que.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}
int main(){
    fastIO;
    while(cin>>n){
        rep(i,1,n) rep(j,1,n) cin>>d[i][j];
        ll ans1=0,ans2=0;
        spfa(1);
        ans1=dis[n];
        ans2=dis[1];
        spfa(n);
        ans2+=dis[n];
        cout<<min(ans1,ans2)<<endl;
    }
    return 0;
}