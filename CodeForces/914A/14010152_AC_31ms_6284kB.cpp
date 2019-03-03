#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
using namespace std;
const int MAXN = 4e5+11;
const int INF = 0x7fffffff;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll a[MAXN],n,sq[MAXN];
int main(){
	int j=1,cnt=1;
	while(1){
		if(j*j<=1000000) sq[++cnt]=j*j;
		else break;
		j++;
	}
	while(cin>>n){
		rep(i,1,n) a[i]=read();
		ll mx=-666666666;
		rep(i,1,n){
			int t=lower_bound(sq+1,sq+1+cnt,a[i])-sq;
			if(sq[t]!=a[i]) mx=max(mx,a[i]);
		}
		println(mx);
	}
	return 0;
} 