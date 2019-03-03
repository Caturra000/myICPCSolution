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
inline bool in(ll t,ll a,ll b){
	return t>=a&&t<=b;
}

int main(){
	int T=read();
	while(T--){
		ll a=read();
		ll b=read();
		ll c=read();
		ll d=read();
		ll ans=0;
		ll x=0,y=0;
		rrep(i,61,0){
			bool pos1=(a>>i)&1;
			bool pos2=(b>>i)&1;
			bool pos3=(c>>i)&1;
			bool pos4=(d>>i)&1;
			if(pos1==pos2&&pos3==pos4){//0011 1100 0000 1111
				if(pos1^pos3){
					ans+=(1ll<<i);
				}
			}else if(pos1^pos2&&pos3==pos4){//0100 0111
				ans+=(1ll<<i);
				if(pos3) b=(1ll<<i)-1;
				else a=0;
			}else if(pos1==pos2&&pos3^pos4){
				ans+=(1ll<<i);
				if(pos1) d=(1ll<<i)-1;
				else c=0;
			}else{
				ans+=(1ll<<i+1)-1;
				break;
			}
		}
		println(ans);
	}
	return 0;
}