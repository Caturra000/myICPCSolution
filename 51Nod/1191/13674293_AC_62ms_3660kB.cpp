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
	ll weight,cost;
//	bool operator < (const P &rhs) const{
//		if(cost!=rhs.cost) return cost<rhs.cost;
//		return weight<rhs.weight;
//	}
}a[MAXN];
bool cmp(P &a,P &b){
	if(a.weight!=b.weight) return a.weight>b.weight;
}
ll b[MAXN];
int n,m;
int main(){
	while(cin>>n>>m){
		rep(i,1,n) b[i]=read();
		rep(i,1,m){
			a[i].weight=read();
			a[i].cost=read();
		}
//		multiset<P> mp;
//		rep(i,1,m) mp.insert(a[i]); 
		ll ans=0;
		int cnt=0;
		sort(b+1,b+1+n,greater<int>());
		sort(a+1,a+1+m,cmp); 
//		rep(i,1,n){
//			P tmp;tmp.weight=b[i];tmp.cost=0;
//			multiset<P>::iterator it=mp.lower_bound(tmp);
//			if(it==mp.end())break;
//			ans+=(*it).cost;
//			cnt++;
//			mp.erase(it);
////			if(it->second==1) mp.erase(it);
////			else mp[it->first]--;
//		}
		multiset<ll> mts;
		int j=1;
		rep(i,1,n){
			while(j<=m&&a[j].weight>=b[i]){
				mts.insert(a[j].cost);
				j++;
			}
			if(mts.empty()) break;
			ans+=(*mts.begin());
			mts.erase(mts.begin());
			cnt++;
		}
		if(cnt==n) println(ans);
		else printf("No Solution\n");
	}
	return 0;
}