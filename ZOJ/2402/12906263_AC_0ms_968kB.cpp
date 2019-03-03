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
const int maxn = 1e3+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll dp[12][6666];//长度为i的第i位大小位j的方案数 //ans:dp[n][1..m] 
//dp[i][j]=Σdp[i-1][1...j/2] 
ll sum[6666];
int main(){
	int T=read(),kase=0;
	rep(i,1,2000) dp[1][i]=1;
		rep(i,2,10){
			rep(j,1,2000){
				sum[j]=sum[j-1]+dp[i-1][j];
				dp[i][j]=sum[j/2];
			}
		}
	while(T--){
		int n=read();
		int m=read();
		ll ans=0;
		rep(i,1,m) ans+=1ll*dp[n][i];
		printf("Case %d: n = %d, m = %d, # lists = %lld\n",++kase,n,m,ans);
	}
	return 0;
}