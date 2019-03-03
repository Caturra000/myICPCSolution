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
const int MAXN = 522+11;
const int INF  = 0x3f3f3f3f;
const double EPS = 1e-7;
ll dp[MAXN][MAXN];
ll n,m,mod;
char G[MAXN][MAXN];
int cnt[MAXN];
int main(){
    fastIO;
    while(cin>>n>>m>>mod){
        memset(dp,0,sizeof dp);
        rep(i,1,m) cin>>G[i]+1;
        memset(cnt,0,sizeof cnt);
        rep(i,1,m) rep(j,1,n){
            if(G[i][j]=='1') cnt[j]++;
        }
        int s1=0,s2=0;
        rep(i,1,n) if(cnt[i]==0) s1++;
        rep(i,1,n)  if(cnt[i]==1) s2++;
        dp[s1][s2]=1;
        rep(i,m+1,n){
            rep(j,0,n){
                int k=(n-i+1)*2-j*2;
                if(j>=2&&k<=n-2)dp[j-2][k+2]+=dp[j][k]*j*(j-1)/2,dp[j-2][k+2]%=mod;
                if(j>=1)dp[j-1][k]+=dp[j][k]*j*k,dp[j-1][k]%=mod;
                if(k>=2)dp[j][k-2]+=dp[j][k]*k*(k-1)/2,dp[j][k-2]%=mod;
            }
        }
        cout<<dp[0][0]<<endl;
    }
    return 0;
}