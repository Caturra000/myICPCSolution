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
ll dp[1002][1<<12],n,m,q,a[1002],_2[33];//2开大点,m范围与题面不符 
int main(){
	_2[0]=1;rep(i,1,30)_2[i]=_2[i-1]*2;
	while(cin>>n>>m>>q){
		memset(dp,0,sizeof dp);
		rep(i,1,n) a[i]=read();
		rep(i,1,n){
			for(int j=0;j<=(1<<m)-1;j++){
				int cnt=0;
				for(int k=1;k<m;k++)if((j>>k)&1)cnt++;//0位(距离i最远)不计入
				if(cnt<=q)dp[i][j>>1]=max(dp[i][j>>1],dp[i-1][j]);
				if(cnt<q) dp[i][(j>>1)+_2[m-1]]=max(dp[i][(j>>1)+_2[m-1]],dp[i-1][j]+a[i]);
			}
		}
		ll ans=-1;
		rep(i,1,n) for(int j=0;j<=(1<<m)-1;j++)ans=max(ans,dp[i][j]);
		println(ans);
	}
	return 0;
} 