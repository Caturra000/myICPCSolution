#include<iostream>
#include<algorithm>
#include<stdio.h>
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
const int MAXN = 5e5+11;
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
int L[MAXN],R[MAXN],a[MAXN],n,m;
struct P{
	int mx,mn;
}b[MAXN];
bool cmp(P a,P b){
	if(a.mx!=b.mx) return a.mx<b.mx;
	return a.mn<b.mn;
}
int main(){
	while(cin>>n>>m){
		rep(i,1,n){
			L[i]=read();
			R[i]=read();
		}
		rep(i,1,m) a[i]=read();
		rep(i,1,n-1){
			b[i].mx=R[i+1]-L[i];
			b[i].mn=L[i+1]-R[i];
		}
		sort(b+1,b+n,cmp);
		int cur1=1,cur2=1;
		int cnt=0;
		multiset<int> mst;
		rep(i,1,m) mst.insert(a[i]);
		rep(i,1,n-1){
			multiset<int>::iterator it=mst.lower_bound(b[i].mn);
			if(it==mst.end()||(*it)>b[i].mx) break;
			cnt++;mst.erase(it);
		}
		if(cnt==n-1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}