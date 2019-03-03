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
int n,m,a[23333],dep;
bool dfs(int x){
	if(a[x-1]>n||a[x-1]<=a[x-2])return 0;
	if(x>dep){
		if(a[x-1]==n) return 1;
		else return 0;
	}
//	rep(i,1,x-1){
//		rep(j,1,x-1){
	rrep(i,x-1,1){
		rrep(j,x-1,i){
			a[x]=a[i]+a[j];
			if(dfs(x+1))return 1;
		}
	}
	return 0;
}
int main(){
	IOS;
	while(cin>>n){
		if(n==0)break;
		if(n==1){
			cout<<1<<endl;
			continue;
		}
		a[1]=1;
		rep(depth,2,oo){
			dep=depth;
			if(dfs(2)){
				rep(i,1,depth-1) cout<<a[i]<<" ";
				cout<<a[depth]<<endl;
				break;
			}
		}
	}
	return 0;
}