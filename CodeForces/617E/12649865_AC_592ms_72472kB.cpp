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
const int maxn = 2e6+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct Query{
	int l,r,id;
}q[maxn];
int size;
bool cmp(Query a,Query b){
	if(a.l/size!=b.l/size) return a.l/size<b.l/size;
	else return a.r<b.r;
} 
ll cnt[maxn],a[maxn];
ll ans[maxn];
int main(){
	int n,m,k;
	while(cin>>n>>m>>k){
		memset(cnt,0,sizeof cnt);
		rep(i,1,n) a[i]=read();
		rep(i,2,n) a[i]^=a[i-1];
		rep(i,1,m){
			q[i].l=read();
			q[i].r=read();
			q[i].id=i;
		}
		size=sqrt(n);
		sort(q+1,q+1+m,cmp);
		int l=1,r=0;//l-1=0 r=0
		cnt[a[0]]++;
		ll tmp=0;
		rep(i,1,m){
			while(l<q[i].l){//删去[l,q[i].l-1] 
				cnt[a[l-1]]--;
				tmp-=cnt[a[l-1]^k];
				l++;
			}
			while(l>q[i].l){//添加[q[i].l,l-1] 
				tmp+=cnt[a[l-2]^k];//l-1-1
				cnt[a[l-2]]++;
				l--;
			}
			while(r<q[i].r){//增加[r+1,q[i].r] 
				tmp+=cnt[a[r+1]^k];
				cnt[a[r+1]]++;
				r++;
			}
			while(r>q[i].r){//删去[q[i].r+1,r] 
				cnt[a[r]]--;
				tmp-=cnt[a[r]^k];
				r--;
			}
			ans[q[i].id]=tmp;
		}
		rep(i,1,m) println(ans[i]);
	}
	return 0;
}