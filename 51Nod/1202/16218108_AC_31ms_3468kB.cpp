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
ll dp[MAXN];
int pos[MAXN],a[MAXN];
int main(){
    fastIO;
    int n;
    while(cin>>n){
        memset(pos,-1,sizeof pos);
        rep(i,1,n) cin>>a[i];
        dp[0]=0;dp[1]=1;pos[a[1]]=1;
        rep(i,2,n){
            if(~pos[a[i]]){
                dp[i]=dp[i-1]*2-dp[pos[a[i]]-1];
            }else{
                dp[i]=dp[i-1]*2+1;
            }
            dp[i]=(dp[i]%MOD+MOD)%MOD;
            pos[a[i]]=i;
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}