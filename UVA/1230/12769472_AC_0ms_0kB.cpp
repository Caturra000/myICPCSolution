#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
using namespace std;
typedef long long ll;
ll fpw(ll a,ll n,ll mod){
	ll ans=1;
	while(n){
		if(n&1) ans=(ans*a)%mod;
		n>>=1;
		a=(a*a)%mod;
	}
	return ans;
}
int main(){
	int T; cin>>T;
	while(T--){
		ll a,n,mod;
		cin>>a>>n>>mod;
		cout<<fpw(a,n,mod)<<endl;
	}
	return 0;
}