#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
typedef long long ll;
using namespace std;
const int MAXN = 1e3+11;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll ooo= 0x3f3f3f3f;
const int MOD = 1000000007;
ll read(){
   ll x=0,f=1;register char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
   return x*f;
}
int n,m,x;
double p[MAXN][37];
double f[MAXN][37][37],g[MAXN][37];
int main(){
    while(cin>>m>>n>>x){//m problems n teams
        if(m==0&&n==0&&x==0) break;
        rep(i,1,n) rep(j,1,m) scanf("%lf",&p[i][j]);
        memset(f,0,sizeof f);
        memset(g,0,sizeof g);
        rep(i,1,n){
            f[i][0][0]=1.0;
            rep(j,1,m){
                f[i][j][0]=f[i][j-1][0]*(1.0-p[i][j]);
                rep(k,1,j){
                    f[i][j][k]=f[i][j-1][k-1]*p[i][j]+f[i][j-1][k]*(1.0-p[i][j]);
                }
            }
            g[i][0]=f[i][m][0];//....
            rep(j,1,m) g[i][j]=g[i][j-1]+f[i][m][j];
        }
        double p1=1.0,p2=1.0;
        rep(i,1,n) p1*=(1.0-g[i][0]),p2*=(g[i][x-1]-g[i][0]);
        printf("%.3f\n",p1-p2);
    }
    return 0;
}