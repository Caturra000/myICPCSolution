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
const int maxn = 233;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
double dp[maxn][maxn][maxn];
int a,b,c;
int main(){
	while(cin>>a>>b>>c){
		memset(dp,0,sizeof dp);
		dp[a][b][c]=1;
		rrep(i,a,0)rrep(j,b,0)rrep(k,c,0){
			int tot=i*j+j*k+i*k;
			if(i&&j)dp[i][j-1][k]+=dp[i][j][k]*i*j/tot; 
			if(j&&k)dp[i][j][k-1]+=dp[i][j][k]*j*k/tot;
			if(k&&i)dp[i-1][j][k]+=dp[i][j][k]*i*k/tot;
		}
		rep(i,1,a-1) dp[a][0][0]+=dp[i][0][0];
		rep(i,1,b-1) dp[0][b][0]+=dp[0][i][0];
		rep(i,1,c-1) dp[0][0][c]+=dp[0][0][i];
		printf("%.12lf ",dp[a][0][0]);
		printf("%.12lf ",dp[0][b][0]);
		printf("%.12lf\n",dp[0][0][c]);
	}
	return 0;
}