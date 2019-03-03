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
struct Node{
	ll p,d,id;
}a[maxn];

bool cmp(Node a,Node b){
	if(a.d!=b.d)return a.d<b.d;
	return a.p>b.p;
}
ll n;
int main(){
	while(cin>>n){	
		ll day=0;
		priority_queue<ll,vector<ll>,greater<ll> > que; 
		while(!que.empty())que.pop();
		rep(i,1,n){
			a[i].p=read();
			a[i].d=read();
			a[i].id=i;
			day=max(day,a[i].d);
		}
		if(n==0){
			println(0);
			continue;
		}
		sort(a+1,a+1+n,cmp);
		ll ans=0;
		int now=1;
		rep(i,1,day){
			while(a[now].d<i) now++;
			while(a[now].d==i&&que.size()<i&&now<=n){
				que.push(a[now].p);now++;
			}
			while(a[now].d==i&&que.size()==i&&now<=n&&que.top()<a[now].p){
				que.pop();
				que.push(a[now].p);
				now++;
			}
		}
		while(!que.empty()){
			ans+=que.top();
			que.pop();
		}
		println(ans);
	}
	return 0;
} 