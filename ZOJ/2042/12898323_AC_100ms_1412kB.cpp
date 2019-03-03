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
bool dp[maxn][111];
int a[maxn];
int main(){
	int T=read();
	while(T--){
		int n=read();
		int k=read();
		memset(dp,0,sizeof dp);
		rep(i,1,n){
			a[i]=read();
			a[i]=(a[i]%k+k)%k;//[0,k-1]
		}
		dp[0][0]=1;dp[1][a[1]]=1;
		rep(i,2,n){
			rep(j,0,k-1){
				dp[i][(j+a[i]+k)%k]|=dp[i-1][j];
				dp[i][(j-a[i]+k)%k]|=dp[i-1][j];//note
			}
		}
		if(dp[n][0]) printf("Divisible\n");
		else printf("Not divisible\n");
		if(T) enter;
	}
	return 0;
}