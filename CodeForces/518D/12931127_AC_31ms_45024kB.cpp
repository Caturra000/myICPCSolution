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
const int maxn = 2333+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
double dp[maxn][maxn];//支撑前i天的最小代价,j当天买瓜1不买0
int main(){
	int n,t;double p;
	while(cin>>n>>p>>t){
		dp[0][0]=1;
		rep(i,1,n)dp[0][i]=0;
		rep(i,1,t){
			rep(j,0,n){
				if(j==0) dp[i][0]=(1-p)*dp[i-1][0];
				else if(j==n) dp[i][n]=dp[i-1][n]+p*dp[i-1][n-1];//
				else dp[i][j]=p*dp[i-1][j-1]+(1-p)*dp[i-1][j];
			}
		}
		double ans=0;
		rep(i,1,n) ans+=dp[t][i]*i;
		printf("%.6lf\n",ans);
	}
	return 0;
}