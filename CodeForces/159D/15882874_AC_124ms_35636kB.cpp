#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 2e3+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll f[MAXN][MAXN],g[MAXN];
char str[MAXN];
bool can[MAXN][MAXN];
int main(){
    while(~scanf("%s",str+1)){
        memset(f,0,sizeof f);
        memset(can,0,sizeof can);
        memset(g,0,sizeof g);
        int n=strlen(str+1);
        rep(i,1,n) can[i][i]=f[i][i]=1;
        rep(i,1,n-1){
            if(str[i]==str[i+1]){
                can[i][i+1]=1;
                f[i][i+1]=3;
            }else f[i][i+1]=2;
        }
        rep(len,3,n){
            rep(l,1,n-len+1){
                int r=l+len-1;
                can[l][r]=can[l+1][r-1]&&(str[l]==str[r]);
                f[l][r]=f[l+1][r]+f[l][r-1]-f[l+1][r-1];
                if(can[l][r]) f[l][r]+=1;
            }
        }
        rrep(i,n,1) rrep(j,i,1) g[i]+=can[j][i];
        ll ans=0;
        rep(i,1,n) ans+=g[i]*f[i+1][n];
        println(ans);
    }
}