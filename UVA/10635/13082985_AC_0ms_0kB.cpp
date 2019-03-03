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
const int maxn = 1e5+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[maxn],b[maxn];
int Hash[maxn],dp[maxn];
int main(){
	int T=read(),kase=0;
	while(T--){
		int n=read();
		int p=read();p++;
		int q=read();q++;
		rep(i,1,p)a[i]=read();
		rep(i,1,q)b[i]=read();
		memset(dp,0x3f,sizeof dp);
		memset(Hash,0,sizeof Hash);
		int cnt=1;
		rep(i,1,p){
			if(Hash[a[i]]==0){
				Hash[a[i]]=cnt++;
			}
		}
		rep(i,1,q){
			b[i]=Hash[b[i]];
		}
		int len=0;
		rep(i,1,q){
			if(b[i]==0)continue;
			int pos=lower_bound(dp+1,dp+1+q,b[i])-dp;
			dp[pos]=b[i];
			len=max(len,pos);
		}
		printf("Case %d: %d\n",++kase,len);
	}
	return 0;
} 