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
ll dp[MAXN][MAXN],a[MAXN],d[MAXN];
bool can[MAXN][MAXN];
int main(){
    fastIO;
    int T; cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        rep(i,1,n) cin>>a[i];
        rep(i,1,m) cin>>d[i];
        memset(dp,0,sizeof dp);
        memset(can,0,sizeof can);
        rep(i,1,m){
            rep(j,1,n){
                rep(k,j+1,n){
                    if(a[k]-a[j]==d[i]){
                        can[j][k]=can[k][j]=1;
                    }
                }
            }
        }
        for(int len=2;len<=n;len++){
            for(int i=1;i+len-1<=n;i++){
                int j=i+len-1;
                if(can[i][j]&&dp[i+1][j-1]==j-i-1){
                    dp[i][j]=max(dp[i][j],dp[i+1][j-1]+2);
                    continue;
                }
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                for(int k=i+1;k<j;k++){
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
                    if(can[i][k]&&can[k][j]&&a[k]-a[i]==a[j]-a[k]
                        &&dp[i+1][k-1]==k-i-1&&dp[k+1][j-1]==j-k-1){
                            dp[i][j]=max(dp[i][j],1ll*j-i+1);
                            break;
                    }
                    if(can[i][k]&&dp[i+1][k-1]==k-i-1){
                        dp[i][j]=max(dp[i][j],dp[i+1][k-1]+2+dp[k+1][j]);
                    }
                    if(can[k][j]&&dp[k+1][j-1]==j-k-1){
                        dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j-1]+2);
                    }
                }
            }
        }
        cout<<dp[1][n]<<endl;
    }
    return 0;
}