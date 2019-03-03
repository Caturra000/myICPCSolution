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
ll dp[2][MAXN];//yong le duoshao r
int main(){
    fastIO;
    int r,g;
    while(cin>>r>>g){
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        int cur=0,sum=0;
        while(1){
            sum+=cur+1;
            if(sum>r+g) break;
            cur++;
            memset(dp[cur&1],0,sizeof dp[0]);
            rep(i,0,r){
                if(i>sum) break;//用多了 
                if(i+cur>r) break;//越界了 
                dp[cur&1][i+cur]+=dp[cur-1&1][i],dp[cur&1][i+cur]%=MOD;
                // wa: dp[cur&1][i]+=dp[cur-1&1][i+cur-1]
            }
            rep(i,0,r){
                if(i>sum) break;
                //g'=sum-i g-g'>=cur 
                if(g-sum+i>=0) dp[cur&1][i]+=dp[cur-1&1][i],dp[cur&1][i]%=MOD;
            }
        }
        ll ans=0;
        rep(i,0,r) ans=(ans+dp[cur&1][i])%MOD;
        cout<<ans<<endl;
    }
    return 0;
}