#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#include<unordered_map>
#define rep(i,j,k) for( int i=j;i<=k;i++)
#define rrep(i,j,k) for( int i=j;i>=k;i--)
#define erep(i,u) for( int i=head[u];~i;i=nxt[i])
#define fastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using P  = pair<ll,ll>;
const int MAXN = 2e5+11;
const int INF  = 0x3f3f3f3f;
const double EPS = 1e-7;
ll a[MAXN],pre[MAXN],b[MAXN],n,t;
struct FT{
    ll ft[MAXN<<1];
    inline int lowbit(int x){return x&-x;}
    void init(int n){memset(ft,0,(n<<1|1)*sizeof(long long));}
    void update(int k,ll v){for(;k<MAXN;k+=lowbit(k)) ft[k]+=v;}
    ll query(int k){ll sum=0;for(;k>0;k-=lowbit(k)) sum+=ft[k]; return sum;}
}ft;
int main(){
    fastIO;
    while(cin>>n>>t){
        rep(i,1,n) cin>>a[i];
        rep(i,1,n) b[i]=pre[i]=pre[i-1]+a[i]; b[n+1]=0;
        sort(b+1,b+2+n);
        int m=unique(b+1,b+2+n)-(b+1);
        ft.init(m); ft.update(lower_bound(b+1,b+1+m,0)-b,1);
        //rep(i,1,n) sum[i]-sum[x]<t sum[x]>sum[i]-t;
        ll ans=0;
        rep(i,1,n){
            ll tmp=pre[i]-t;
            ll pos=upper_bound(b+1,b+2+n,tmp)-b;
            if(pos<=n+1){
                pos--;
                ans+=ft.query(n+1)-ft.query(pos);
            }
            ft.update(lower_bound(b+1,b+1+m,pre[i])-b,1);
        }
        
        cout<<ans<<endl;
    }
    return 0;
}