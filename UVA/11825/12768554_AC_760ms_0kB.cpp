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
int main(){
	int kase=0,n,m,x,P[666],U[1<<17|1],dp[1<<17|1];
	while(cin>>n){
		if(n==0)break;
		rep(i,0,n-1){
			m=read();
			P[i]=1<<i;
			rep(j,1,m){
				x=read();
				P[i]|=(1<<x);
			}
		}
		rep(S,0,(1<<n)-1){//并集枚举 
			U[S]=0;
			rep(i,0,n-1){
				if((S>>i)&1) U[S]|=P[i];
			}
		}
		dp[0]=0; x=(1<<n)-1;
		rep(S,1,(1<<n)-1){
			dp[S]=0;
			for(int S0=S;S0;S0=(S0-1)&S){
				if(U[S0]==x) dp[S]=max(dp[S],dp[S^S0]+1);
			}
		}
		printf("Case %d: %d\n",++kase,dp[(1<<n)-1]);
	}
	return 0; 
} 