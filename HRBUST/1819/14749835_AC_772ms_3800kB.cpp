#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 4e2+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll f[MAXN][MAXN],g[MAXN][MAXN],a[MAXN];
ll sum[MAXN],n;
int main(){
    while(cin>>n){
        rep(i,1,n) a[i]=read();
        rep(i,n+1,n<<1) a[i]=a[i-n];
        //rep(i,1,n<<1) cout<<a[i]<<" ";cout<<endl;
        memset(f,0x3f,sizeof f);
        memset(g,0x80,sizeof g);
        rep(i,1,n<<1) f[i][i]=g[i][i]=0;
        rep(i,1,n<<1) sum[i]=sum[i-1]+a[i];
        rep(len,2,n<<1){
            rep(l,1,n*2-len+1){
                int r=l+len-1;
                rep(k,l,r-1){
                    f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]);
                    g[l][r]=max(g[l][r],g[l][k]+g[k+1][r]);
                }
                f[l][r]+=sum[r]-sum[l-1];
                g[l][r]+=sum[r]-sum[l-1];
            }
        }
        ll ans1=1ll<<61,ans2=0;
        rep(i,1,n) ans1=min(ans1,f[i][i+n-1]),ans2=max(ans2,g[i][i+n-1]);
        printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}