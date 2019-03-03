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
bool GCD[1002][1002];
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	rep(i,1,1000) rep(j,1,1000) GCD[i][j]=bool(gcd(i,j)==1);
	int T=read(),kase=0;
	while(T--){
		int n=read();
		if(n==1){
			printf("%d %d 3\n",++kase,n);
			continue;
		}
		int ans=0;
		rep(i,1,n) rep(j,1,n) ans+=GCD[i][j];
		ans+=2;
		printf("%d %d %d\n",++kase,n,ans);
	}
	return 0;
} 