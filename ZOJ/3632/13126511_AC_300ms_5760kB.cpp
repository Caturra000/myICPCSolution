#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<bitset>
#include<set>
#include<map>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iin(a) scanf("%d",&a)
#define lin(a) scanf("%lld",&a)
#define din(a) scanf("%lf",&a)
#define s0(a) scanf("%s",a)
#define s1(a) scanf("%s",a+1)
#define print(a) printf("%lld",(ll)a)
#define enter putchar('\n')
#define blank putchar(' ')
#define println(a) printf("%lld\n",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int maxn = 1e5+11;
const int MOD = 2520;
const double eps = 1e-10;
typedef long long ll;
const ll oo = 1ll<<60;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll dp[maxn],a[maxn],b[maxn],n;
struct ST{
    ll mn[maxn<<2];
    #define lc o<<1
    #define rc o<<1|1
    void build(int o,int l,int r){
        mn[o]=oo;
        if(l==r)return;
        int m=l+r>>1;
        build(lc,l,m);
        build(rc,m+1,r);
    }
    void pu(int o){
        mn[o]=min(mn[lc],mn[rc]);
    }
    void update(int o,int l,int r,int k,ll v){
        if(l==r){
            mn[o]=min(v,mn[o]);
            return;
        }
        int m=l+r>>1;
        if(k<=m) update(lc,l,m,k,v);
        else update(rc,m+1,r,k,v);
        pu(o);
    }
    ll query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R) return mn[o];
        int m=l+r>>1;
        ll ans=oo;
        if(L<=m) ans=min(ans,query(lc,l,m,L,R));
        if(R>m) ans=min(ans,query(rc,m+1,r,L,R));
        return ans;
    }
}st;
int main(){
    while(cin>>n){
        rep(i,1,n) a[i]=read();
        rep(i,1,n) b[i]=min(read(),n);
        st.build(1,1,n);
        dp[0]=0;
        dp[1]=a[1];st.update(1,1,n,b[1],dp[1]);
        rep(i,2,n){
            dp[i]=dp[i-1]+a[i];
            st.update(1,1,n,min(i+b[i]-1,n),dp[i]);//mai gua
            ll t=st.query(1,1,n,i,n);//xu ming
            if(t<dp[i]) dp[i]=t;
        }
        println(min(dp[n],st.query(1,1,n,n,n)));
    }
    return 0;
}