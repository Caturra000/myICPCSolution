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
const int maxn = 333+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,a[maxn],b[maxn];
ll dp[maxn][maxn];//支撑前i天的最小代价,j当天买瓜1不买0
int main(){
	int T=read(),kase=0;
	while(T--){
		n=read();
		rep(i,1,n) a[i]=read();
		rep(i,1,n) b[i]=read();b[n+1]=0;
		rep(i,1,n)rep(j,i,n)dp[i][j]=1ll<<33;
		rep(i,1,n) dp[i][i]=a[i]+b[i-1]+b[i+1];
		rep(i,1,n) dp[0][i]=dp[i][n+1]=oo;
		rep(len,2,n){
			rep(i,1,n-len+1){
				int j=i+len-1;
				rep(k,i,j){
					dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[k]+b[i-1]+b[j+1]);
				}
			}
		}
		printf("Case #%d: ",++kase);
		println(dp[1][n]);
	}
	return 0;
}