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
int a[666],tot,ans,sum,n;
bool used[666];
bool dfs(int x,int y,int z){
	if(x==tot+1) return 1;
	if(z==sum/tot)  return dfs(x+1,1,0);
	if(y==n+1) return 0; 
	int failed=0;//!!!
	rep(i,y,n){
		if(!used[i]&&z+a[i]<=sum/tot&&failed!=a[i]){
			used[i]=1;
			if(dfs(x,y+1,z+a[i])) return 1;
			failed=a[i];
			used[i]=0;
			if(z==0)return 0;//!!!
		}
	}
	return 0;
}
int main(){
	while(~iin(n)){
		if(n==0)break;
		rep(i,1,n) a[i]=read();
		sort(a+1,a+1+n,greater<int>());
		sum=0;
		rep(i,1,n) sum+=a[i];
		ll ans=oo;
		rrep(i,sum,1){
			if(sum%i==0){
				tot=i;
				memset(used,0,sizeof used);
				if(dfs(1,1,0)){
					 ans=min(ans,(ll)sum/tot);
					 break;
				}
			}
		}
		println(ans);
	}
	return 0;
} 