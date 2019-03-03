#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e3+11;
typedef long long ll;
const ll MOD = 1e9+7;
const ll INF = 1ll<<60;
const double EPS = 1e-7;
unsigned int SEED = 19260817;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
double f[MAXN*10][MAXN],p[MAXN];
int k,q;
int main(){
    while(cin>>k>>q){
        rep(i,1,q) scanf("%lf",&p[i]);
        memset(f,0,sizeof f);
        f[0][0]=1.0;
        rep(i,1,MAXN*10-1){
            rep(j,1,MAXN-1){
                f[i][j]=f[i-1][j]/k*j+f[i-1][j-1]/k*(k-j+1);
            }
        }
        rep(i,1,q) rep(j,1,MAXN*10-1){
            if(f[j][k]>=(p[i]-EPS)/2000.0){
                println(j);break;
            }
        }
    }
    return 0;
}