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
const int maxn = 5e3+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int mt[maxn][maxn]; 
int main(){
	int n,R,x,y,v;
	while(~iin(n)){
		R=read();
		memset(mt,0,sizeof mt);
		rep(i,1,n){
			x=read();
			y=read();
			v=read();
			x++;y++;
			mt[x][y]+=v;
		}
		rep(i,1,maxn-1) rep(j,1,maxn-1) mt[i][j]+=mt[i][j-1];
		rep(i,1,maxn-1) rep(j,1,maxn-1) mt[i][j]+=mt[i-1][j];
		ll ans=0;
		rep(i,R,maxn-1) rep(j,R,maxn-1){
			ans=max(ans,1ll*mt[i][j]-mt[i-R][j]-mt[i][j-R]+mt[i-R][j-R]);
		}
		println(ans);
	}
	return 0;
}