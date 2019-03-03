#include<bits/stdc++.h>
const int mod = 1e9+7;
using namespace std;
string str;int k;
typedef long long ll;
ll fastpow(ll a,ll n){
	ll sum=1;
	for(; n; n>>=1,a=a*a%mod){
		if(n&1) sum=sum*a%mod;
	}
	return sum%mod;
}
ll extgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll d = extgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-a/b*y;
	return d; 
}
ll inverse(ll t){
	ll x,y;
	ll d=extgcd(t,mod,x,y);
	return (x%mod+mod)%mod;
}
int main(){
	while(cin>>str>>k){
		ll q = fastpow(2,str.length());
		ll ans=0;
		for(int i = 0; i < str.length(); i++){
			if(str[i]=='0'||str[i]=='5'){
				ll t = fastpow(2,i);
				ans=(ans+t*(fastpow(q,k)-1)%mod*inverse(q-1))%mod;
			}
		}
		cout<<ans<<endl;
	}
}