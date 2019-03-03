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
const int MAXN = 1e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
const ll MOD = 1e9+7; 
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct P{
	int a,b;
}a[MAXN];
bool cmp(P a,P b){
	if(a.a-a.b!=b.a-b.b) return a.a-a.b>b.a-b.b;
	else return a.a>b.b;
}
int n;
int main(){
	while(cin>>n){
		rep(i,1,n){
			a[i].a=read();
			a[i].b=read();
		}
		sort(a+1,a+1+n,cmp);
		int cur=0,ans=0;
		rep(i,1,n){
			cur-=a[i-1].a;
			cur+=a[i-1].b;
			cur+=a[i].a;
			ans=max(cur,ans);
		}
		println(ans);
	}
	return 0;
}