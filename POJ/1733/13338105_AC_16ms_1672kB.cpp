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
const int maxn = 2e5+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int p[maxn],r[maxn];
void init(int n){
	memset(r,0,sizeof r);
	rep(i,0,n+2) p[i]=i;
}
int find(int x){
	if(x==p[x])return x;
	int oldp=p[x];
	int t=find(p[x]);
	r[x]=(r[x]+r[oldp])&1;
	return p[x]=t;
}
void link(int fa,int fb,int a,int b,int w){
	p[fb]=fa;
	r[fb]=(r[a]-r[b]+w+4)&1;
//	r[fb]=(r[a]+r[b]+w+4)%2;
}
int b[maxn],n,m,tot;
struct P{
	int a,b;
	bool odd;
}a[maxn];
char s[66];
inline int pos(int i){
	return lower_bound(b+1,b+1+tot,i)-b;
}
int main(){
	while(cin>>n>>m){
		tot=0;
		rep(i,1,m){
			scanf("%d%d%s",&a[i].a,&a[i].b,s);
			if(s[0]=='e')a[i].odd=0;
			else a[i].odd=1;
			if(a[i].a>a[i].b)swap(a[i].a,a[i].b);
			a[i].a--;
			b[++tot]=a[i].a;
			b[++tot]=a[i].b;
		}
		sort(b+1,b+1+tot);
		int nn=unique(b+1,b+1+tot)-b-1;
		tot=nn;
		init(nn);
		int flag=0;
		rep(i,1,m){
			int x=pos(a[i].a),y=pos(a[i].b);
			int odd=a[i].odd;
			int fx=find(x),fy=find(y);
			if(flag)continue;
			if(fx==fy){
				if(((r[y]-r[x]+4)&1)!=odd){
					flag=i;
				}
			}else{
				link(fx,fy,x,y,odd);
			}
		}
		printf("%d\n",flag==0?m:flag-1);
	}
	return 0;
}