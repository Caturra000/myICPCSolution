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
const int maxn = 5e5+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll dp1[maxn],dp2[maxn];
ll a[maxn],n;
int main(){
	while(~iin(n)){
		rep(i,1,n) a[i]=read();
		memset(dp1,0x80,sizeof dp1);dp1[1]=a[1];
		memset(dp2,0x80,sizeof dp2);dp2[n]=a[n];
//		rep(i,1,n) dp1[i]=max(dp1[i-1]+a[i],a[i]);
//		rrep(i,n,1) dp2[i]=max(dp2[i+1]+a[i],a[i]);
		ll sum=0;
		rep(i,1,n){
			if(sum<0) sum=0;
			sum+=a[i];
			dp1[i]=max(dp1[i-1],sum);
		}
		sum=0;
		rrep(i,n,1){
			if(sum<0)sum=0;
			sum+=a[i];
			dp2[i]=max(dp2[i+1],sum);
		}
		ll ans=1ll<<63;ans=-ans;
		rep(i,2,n-1) ans=max(ans,dp1[i-1]+dp2[i+1]);
		println(ans);
	}
	return 0;
}