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
bool dp[maxn][maxn];
char a[maxn],b[maxn],c[maxn];
int main(){
	int T=read(),kase=0;
	while(T--){
		s1(a);s1(b);s1(c);
		memset(dp,0,sizeof dp);
		int la=strlen(a+1),lb=strlen(b+1),lc=strlen(c+1);
		dp[0][1]=bool(b[1]==c[1]);
		dp[1][0]=bool(a[1]==c[1]); 
		rep(i,2,la) dp[i][0]|=(dp[i-1][0]&&a[i]==c[i]);
		rep(i,2,lb) dp[0][i]|=(dp[0][i-1]&&b[i]==c[i]);
		rep(i,1,la) rep(j,1,lb){
			dp[i][j]|=(dp[i-1][j]&&a[i]==c[i+j]);
			dp[i][j]|=(dp[i][j-1]&&b[j]==c[i+j]);
		}
		if(dp[la][lb]) printf("Data set %d: yes\n",++kase);
		else printf("Data set %d: no\n",++kase);
	}
	return 0;
}