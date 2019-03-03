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
const int maxn = 1e4+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int dp[2][maxn];
struct qwe{
	int a,b;
}t[maxn];
bool cmp(qwe a,qwe b){
	return a.b<b.b;
}
int main(){
	int T=read();
	while(T--){
		int n=read();
		int m=read();
		rep(i,1,n) t[i].a=read();
		rep(i,1,n) t[i].b=read();
		sort(t+1,t+1+n,cmp);
		memset(dp,0,sizeof dp);
		rep(i,1,n){
			rep(j,1,m){
				dp[i&1][j]=max(dp[i-1&1][j],dp[i-1&1][j-1]+t[i].a+t[i].b*(j-1));
			}
		}
		println(dp[n&1][m]);
	}
	return 0;
}