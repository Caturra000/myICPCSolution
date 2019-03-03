#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll quick_pow(ll a,ll n,ll mmod){
    ll ans = 1;
    while(n){
        if(n&1) ans = ans*a%mmod;
        a = a*a%mmod;
        n >>= 1;
    }
    return ans;
}
int main(){
	ll n;
	while(scanf("%lld",&n)!=EOF){
		printf("%lld\n",quick_pow(n,n,10));
	}
	return 0;
}