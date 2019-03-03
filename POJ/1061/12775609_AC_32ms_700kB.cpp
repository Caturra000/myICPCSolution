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
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;y=0;
		return a;
	}else{
		ll gcd=exgcd(b,a%b,x,y);
		ll tmp=x;
		x=y;y=tmp-a/b*x;
		return gcd; 
	}
}
int main(){
	int kase=0;
	ll x,y,m,n,L,MOD;	
	while(cin>>x>>y>>m>>n>>L){
		ll t,k;
		ll gcd=exgcd(n-m+L,L,t,k);
		if((x-y+L)%gcd!=0) cout<<"Impossible"<<endl;
		else{
			t=t*(x-y+L)/gcd;
			MOD=L/gcd;
			t=(t%MOD+MOD)%MOD;
			cout<<t<<endl;
		}
	}
	return 0;
} 