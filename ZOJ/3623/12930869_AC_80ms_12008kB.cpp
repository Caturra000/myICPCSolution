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
int n,L,cost[maxn],weight[maxn],tot;
int dp[maxn];
int main(){
	while(cin>>n>>L){
		rep(i,1,n){
			cost[i]=read();
			weight[i]=read();
		}
		memset(dp,0,sizeof dp);
		int ans=oo;
		//时间为j时能生产船伤害的最大总值 
//		rep(i,1,n){
//			rep(j,cost[i],n*L){
//				dp[j]=max(dp[j],dp[j-cost[i]]+weight[i]);
//				if(dp[j]==0) continue;
//				else ans=min(ans,max(1ll*j,(ll)ceil(1.0*L/dp[j])));//这个是必须建好后一起攻击 
//			}
//		} 
		rep(i,1,n){
			rep(j,cost[i],6667){
				dp[j]=max(dp[j],dp[j-cost[i]]+(j-cost[i])*weight[i]);
			}
		}
		rep(i,1,6667) if(dp[i]>=L) ans=min(ans,i); 
		println(ans);
	}
	return 0;
}