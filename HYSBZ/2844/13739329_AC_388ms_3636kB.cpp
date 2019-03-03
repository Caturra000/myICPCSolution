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
const int MAXN = 3e5+11;
const double EPS = 1e-7;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 10086; 
unsigned int SEED = 17;
const ll INF = 1ll<<60;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll a[MAXN],b[66],n,cnt;
vector<ll> vec;
void cal(int n){
    memset(b,0,sizeof b);cnt=0;
    rep(i,1,n){
        rrep(j,62,0){
            if(a[i]>>j&1){
                if(b[j]) a[i]^=b[j];
                else{
                    b[j]=a[i];cnt++;
                    rrep(k,j-1,0) if(b[k]&&(b[j]>>k&1))b[j]^=b[k];
                    rep(k,j+1,62) if(b[k]>>j&1) b[k]^=b[j];
                    break;
                }
            }
        }
    }
}
ll fpw(ll a,ll n,ll mod){
    ll res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        n>>=1;a=(a*a)%mod;
    }
    return res;
}
int main(){
    while(cin>>n){
        rep(i,1,n) a[i]=read();
        cal(n);
        vec.clear();
        rep(i,0,62) if(b[i]) vec.push_back(i);
        ll x=read(), rk=0;
        for(int i=0;i<vec.size();i++) if(x>>vec[i]&1) rk|=(1<<i);
        ll res=rk%MOD*fpw(2,n-cnt,MOD)%MOD+1;
        println(res%MOD);
    }
    return 0;
}