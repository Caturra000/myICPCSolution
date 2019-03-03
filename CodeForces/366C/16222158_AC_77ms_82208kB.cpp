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
const int MAXN = 2e5+11;
const int INF  = 0x3f3f3f3f;
const int MOD  = 1e9+7;
const double EPS = 1e-7;
int dp[105][MAXN];
int a[233],b[233];
const int D = 1e5+11;
int main(){
    fastIO;
    int n,k;
    while(cin>>n>>k){
        rep(i,0,n) rep(j,0,MAXN-1) dp[i][j]=-INF;
        rep(i,1,n) cin>>a[i];
        rep(i,1,n) cin>>b[i];
        dp[0][D]=0;
        rep(i,1,n){
            rep(j,0,D<<1){
                int t=a[i]-k*b[i];
                if(j-t<0) continue;
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-t]+a[i]);
            }
        }
        if(dp[n][D]<=0) cout<<-1<<endl;
        else cout<<dp[n][D]<<endl;
    }
    return 0;
}