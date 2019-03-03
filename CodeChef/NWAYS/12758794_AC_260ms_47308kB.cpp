#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int maxn = 2e6+111;////
ll jie[maxn],inv[maxn];
ll fpw(ll a,ll n){
	ll ans=1;
	while(n){
		if(n&1) ans=(ans*a)%mod;
		n>>=1; a=(a*a)%mod;
	}
	return ans;
}
ll C(ll n,ll k){
	ll up=jie[n];
	ll down=inv[k]*inv[n-k]%mod;
	return (up*down)%mod;
}
int main(){
	ll T; scanf("%lld",&T);
	jie[0]=inv[0]=1;
	rep(i,1,maxn-2) jie[i]=(jie[i-1]*i)%mod;
	rep(i,1,maxn-2) inv[i]=fpw(jie[i],mod-2);
	while(T--){
    	ll n,k; scanf("%lld%lld",&n,&k);
//    	ll tmp=jie[n+k+1]*(inv[n-1]*inv[k+2]%mod)%mod;
    	ll tmp=C(n+k+1,k+2);
    	ll ans=((tmp*2)%mod-n+mod)%mod;
    	printf("%lld\n",ans);
	}
    return 0;
}