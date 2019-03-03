#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#include<unordered_map>
#define rep(i,j,k) for( int i=j;i<=k;i++)
#define rrep(i,j,k) for( int i=j;i>=k;i--)
#define erep(i,u) for( int i=head[u];~i;i=nxt[i])
#define fastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
const int MAXN = 4e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
using ll = long long;
using P  = pair<ll,ll>;
int l[MAXN],r[MAXN];
long double pp[MAXN];
int main(){
    fastIO;
    ll n,p;
    while(cin>>n>>p){
        long double ans=0;
        rep(i,1,n) cin>>l[i]>>r[i];
        rep(i,1,n) pp[i]=(r[i]/p-(l[i]-1)/p);
        rep(i,1,n) pp[i]/=(long double)(r[i]-l[i]+1);
        rep(i,1,n) pp[i]=1.0-pp[i];
        rep(i,1,n) ans+=(1.0-pp[i]*pp[i%n+1]);
        cout<<fixed<<setprecision(12)<<ans*2e3<<endl;
    }
    return 0;
}
