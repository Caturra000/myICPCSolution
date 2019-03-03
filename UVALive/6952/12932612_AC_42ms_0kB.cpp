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
const int maxn = 1e5+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll dp[22][maxn],p[maxn];
int n,d;
inline ll cal(ll x){
	return (x+5)/10*10;
}
int main(){
	while(cin>>n>>d){
		memset(dp,0x3f,sizeof dp);
		rep(i,1,n) p[i]=read();
		dp[1][1]=p[1];
		rep(i,2,n) dp[1][i]=dp[1][i-1]+p[i];
		rep(i,2,d+1){
			rep(j,i,n){
				dp[i][j]=min(cal(dp[i-1][j-1])+p[j],dp[i][j-1]+p[j]);
			}
		}
		ll ans=oo;
		rep(i,1,d+1) ans=min(ans,cal(dp[i][n]));
		println(ans);
	}
	return 0;
} 
