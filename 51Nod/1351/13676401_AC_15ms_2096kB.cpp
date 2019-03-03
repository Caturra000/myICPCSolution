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
int lo[MAXN],hi[MAXN];
int main(){
	int n,c,x,T=read();
	while(T--){
		cin>>n>>c>>x;
		rep(i,1,n){
			lo[i]=read();
			hi[i]=read();
		}
		sort(lo+1,lo+1+n,greater<int>());
		sort(hi+1,hi+1+n);
		ll sum=0,cnt=0;
		rep(i,1,n){
			sum+=lo[i];
			cnt++;
			if(sum>=x)break;
		}
		ll ans=cnt;cnt=n;sum=0;
		rep(i,1,n){// C - mei chi de 
			if(c-sum-hi[i]>=x){
				sum+=hi[i];
				cnt--;
			}else break;
		}
		ans=min(ans,cnt);
		println(ans);
	}
	return 0;
}