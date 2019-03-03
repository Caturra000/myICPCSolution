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
#include<set>
#include<map>
#include<bitset>
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
const int MAXN = 1e6+11;
const double EPS = 1e-7;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7; 
unsigned int SEED = 17;
const ll INF = 1ll<<60;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll a[MAXN],b[66],n;
bool flag=1;
ll cal(){
    memset(b,0,sizeof b);
    flag=1;
    rep(i,1,n){
        rrep(j,62,0){
            if(a[i]>>j&1){
                if(b[j]) {a[i]^=b[j];flag&=bool(a[i]>0);}
                else{
                    b[j]=a[i];
                    rrep(k,j-1,0) if(b[k]&&(b[j]>>k&1))b[j]^=b[k];
                    rep(k,j+1,62) if(b[k]>>j&1) b[k]^=b[j];
                    break;
                }
            }
        }
    }
    sort(b,b+62+1);
    return unique(b,b+63)-b;
}

ll query(int k){
    int cur=b[0]==0?1:0;
    ll ans=0;
    while(k){
        if(k&1) ans^=b[cur];
        k>>=1;cur++;
    }
    return ans;
}
int main(){
    int T=read(),kase=0;
    while(T--){
        n=read();
        rep(i,1,n) a[i]=read();
        int tot=cal();flag^=1;
        int q=read();
        printf("Case #%d:\n",++kase);
        rep(i,1,q){
            ll k=read();if(flag)k--;
            if(k==0) println(0);
            else if(k>=(1ll<<(tot-bool(b[0]==0)))) println(-1);
            else println(query(k));
        }
    }
    return 0;
}
