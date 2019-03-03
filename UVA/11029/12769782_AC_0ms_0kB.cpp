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
		cin>>a>>n;
		ll ans2=fpw(a,n,1000);
		double tmp=(double)n*log10(a);
		tmp=tmp-(int)tmp;
		ll ans1=pow(10,tmp)*100;
		int len;
		if(ans2<10)len=1;
		else if(ans2<100) len=2;
		else len=3;
		cout<<ans1<<"..."<<string((3-len),'0')<<ans2<<endl;
	}
	return 0;
}