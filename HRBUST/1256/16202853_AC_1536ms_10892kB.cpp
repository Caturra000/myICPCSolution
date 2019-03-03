#include<bits/stdc++.h>
#include<unordered_map>
#include<ext/pb_ds/priority_queue.hpp>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define fastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define println(x) print(x),print('\n')
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pr = pair<ll,ll>;
const int MAXN = 66+11;
const int INF  = 0x3f3f3f3f;
const double EPS = 1e-7;
ll a[MAXN],b[MAXN][MAXN],dp[1<<20];
ll s[2333],val[2333];
bool vis[1<<20];
int main(){
    fastIO;
    int T; cin>>T;
    while(T--){
        int K,n;
        cin>>K>>n;
        rep(i,1,n) cin>>a[i];
        rep(i,1,n) rep(j,1,n) cin>>b[i][j];
        int tot=0;
        rep(i,1,n) rep(j,i+1,n) rep(k,j+1,n){
            s[++tot]=(1<<i-1)|(1<<j-1)|(1<<k-1);
            val[tot]=a[i]+a[j]+a[k]+b[i][j]+b[i][k]+b[j][k];
        }
        memset(dp,0,sizeof dp);
        memset(vis,0,sizeof vis);
        int S=1<<n;
        queue<int> que;
        rep(i,1,tot) que.push(s[i]),dp[s[i]]=val[i];
        rep(i,1,K-1){
            while(!que.empty()){
                int u=que.front(); que.pop();
                rep(j,1,tot) if((u&s[j])==0){
                    int v=u|s[j];
                    dp[v]=max(dp[v],dp[u]+val[j]);
                    if(!vis[v]) vis[v]=1;
                }
            }
            rep(j,0,S-1) if(vis[j]) que.push(j),vis[j]=0;
        }
        ll ans=0;
        rep(i,0,S-1){
            int cnt=0;
            rep(j,0,n-1) cnt+=bool(i>>j&1);
            if(cnt==K*3) ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}