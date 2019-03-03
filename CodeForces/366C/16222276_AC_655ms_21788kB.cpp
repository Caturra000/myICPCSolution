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
const int MAXN = 1e5+11;
const int INF  = 0x3f3f3f3f;
const int MOD  = 1e9+7;
const double EPS = 1e-7;
unordered_map<int,int> dp[2];
int a[233],b[233],n,k;
int main(){
    rep(i,0,1) dp[i].reserve(1024);
    rep(i,0,1) dp[i].max_load_factor(0.25);
    fastIO;
    while(cin>>n>>k){
        rep(i,-MAXN,MAXN) dp[0][i]=-INF;
        dp[0][0]=0;
        rep(i,1,n) cin>>a[i];
        rep(i,1,n) cin>>b[i];
        rep(i,1,n){
            rep(j,-MAXN,MAXN) dp[i&1][j]=-INF;
            rep(j,-MAXN,MAXN){
                int t=a[i]-k*b[i];
                if(j-t<-MAXN) continue;
                dp[i&1][j]=max(dp[i-1&1][j],dp[i-1&1][j-t]+a[i]);
            }
        }
        if(dp[n&1][0]<=0) cout<<-1<<endl;
        else cout<<dp[n&1][0]<<endl;
    }
    return 0;
}