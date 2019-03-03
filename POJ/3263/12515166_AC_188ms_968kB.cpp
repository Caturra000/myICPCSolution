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
typedef pair<int,int> P;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int delta[maxn];
map<P,int> vis;
int main(){
	int n,I,h,r,a,b;
	while(~iin(n)){
	    I=read();h=read();r=read();
		memset(delta,0,sizeof delta);
		vis.clear();
		rep(i,1,r){
			a=read();b=read();
			if(a>b) swap(a,b);//strict prefix
			if(vis[P(a,b)]) continue;
			vis[P(a,b)]=1;
			delta[a+1]--;delta[b]++;//-1 +1
		}
		rep(i,1,n){
			delta[i]+=delta[i-1];
		}
		rep(i,1,n){
			println(delta[i]+h);
		}
	}
	return 0;
}
