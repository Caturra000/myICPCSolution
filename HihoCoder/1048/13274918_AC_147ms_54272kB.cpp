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
const ll mod = 1e9+7; 
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll dp[1003][6][1<<5|1][1<<5|1],n,m;
ll DP(int r,int c,int r1,int r2){
	if(r==n-1&&r1==(1<<m)-1&&r2==(1<<m)-1) return 1;
	if(r==n&&r1==(1<<m)-1) return 1;
	if(~dp[r][c][r1][r2]) return dp[r][c][r1][r2];
	int A=r1>>(c-1),B=r1>>c,C=r2>>(c-1);
	if(c<m&&(A&1)) return dp[r][c][r1][r2]=DP(r,c+1,r1,r2)%mod;
	if(c==m&&(A&1)) return dp[r][c][r1][r2]=DP(r+1,1,r2,0)%mod;
	if(!(A&1)&&(c==m||(B&1))&&(r==n||(C&1)))return dp[r][c][r1][r2]=0;
	if(!(A&1)&&(c<m||!(B&1))&&(r==n||(C&1)))return dp[r][c][r1][r2]=DP(r,c,r1|(1<<c-1)|(1<<c),r2)%mod;
	if(!(A&1)&&(c==m||(B&1))&&(r<n||!(C&1)))return dp[r][c][r1][r2]=DP(r,c,r1|(1<<c-1),r2|(1<<c-1))%mod;
	if(!(A&1)&&(c<m||!(B&1))&&(r<n||!(C&1)))return dp[r][c][r1][r2]=(DP(r,c,r1|(1<<c-1)|(1<<c),r2)+DP(r,c,r1|(1<<c-1),r2|(1<<c-1)))%mod;
}
int main(){
	while(cin>>n>>m){
		memset(dp,-1,sizeof dp);
		println(DP(1,1,0,0)%mod); 
	}
	return 0;
}