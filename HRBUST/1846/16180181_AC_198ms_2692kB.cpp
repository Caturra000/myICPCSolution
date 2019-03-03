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
const int MAXN = 1e5+11;
const int INF  = 0x3f3f3f3f;
const double EPS = 1e-7;
const ll MOD = 1000000007;
ll dp[MAXN],_2[MAXN];
int n,m;
int main(){
    fastIO;
    while(cin>>n>>m){
        memset(dp,0,sizeof dp);
        dp[m]=_2[0]=1;
        rep(i,1,MAXN-1) _2[i]=_2[i-1]*2%MOD;
        rep(i,m+1,n){
            dp[i]=dp[i-1]*2+_2[i-m-1]-dp[i-m-1];
            dp[i]=(dp[i]%MOD+MOD)%MOD;
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
