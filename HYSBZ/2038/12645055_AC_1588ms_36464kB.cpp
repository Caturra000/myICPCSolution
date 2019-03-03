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
inline ll sqr(ll x){
	return x*x;
}
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int size,cnt[maxn],a[maxn];
struct Query{
	int l,r,id;
	ll A,B;
}q[maxn];
bool cmp(Query a,Query b){
	if(a.l/size!=b.l/size) return a.l/size<b.l/size; 
	else return a.r<b.r;
}
bool cmp2(Query a,Query b){
	return a.id<b.id;
}
ll tmp=0;
void modify(int x,int v){
	tmp-=sqr(cnt[a[x]]);
	cnt[a[x]]+=v;
	tmp+=sqr(cnt[a[x]]);
}
int main(){
	int n=read();
	int m=read();
	size=sqrt(n);
	rep(i,1,n){
		a[i]=read();
	}
	rep(i,1,m){
		q[i].l=read();
		q[i].r=read();
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp);
	int l=1,r=0;
	rep(i,1,m){
		while(l<q[i].l){
			modify(l,-1);
			l++;
		}
		while(l>q[i].l){
			modify(l-1,1);
			l--;
		}
		while(r<q[i].r){
			modify(r+1,1);
			r++;
		}
		while(r>q[i].r){
			modify(r,-1);
			r--;
		}
		if(q[i].l==q[i].r){
			q[i].A=0;
			q[i].B=1;
			continue;
		}
		q[i].A=tmp-(q[i].r-q[i].l+1);
		q[i].B=1ll*(q[i].r-q[i].l+1)*(q[i].r-q[i].l);
		ll GCD=gcd(q[i].A,q[i].B);
		q[i].A/=GCD;
		q[i].B/=GCD; 
	}
	sort(q+1,q+1+m,cmp2);
	rep(i,1,m){
		print(q[i].A);
		putchar('/');
		println(q[i].B);
	}
	return 0;
}