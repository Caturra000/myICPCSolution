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
const int maxn = 1e6+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,a[maxn];
ll dp[maxn][2],mx[maxn];
//dp[i][j]:前i个数分j段的最优解
//dp[i][j]=max(dp[i-1][j]+a[i],dp[i-x][j-1]+Σa[i-x+1]) 
//dp[i][j]=max(dp[i-1][j],dp[x][j-1])+a[i]
int main(){
	while(cin>>m>>n){
		rep(i,1,n) a[i]=read();
		memset(dp,0,sizeof dp);
		int t=1;
		rep(j,1,m){
			dp[j][j&1]=dp[j-1][j-1&1]+a[j];//对角线初始化 
			ll mx=dp[j-1][j-1&1];
			rep(i,j+1,n){//i-1>=j
				mx=max(mx,dp[i-1][j-1&1]);
				dp[i][j&1]=max(dp[i-1][j&1],mx)+a[i];
			}
		}
		ll ans=-oo;
		rep(i,m,n) ans=max(ans,dp[i][m&1]);
		println(ans);
	}
	return 0;
}