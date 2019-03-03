#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e6+100;
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
	ll a,n,mod;
	while(scanf("%lld",&n)!=EOF){
		printf("%lld\n",quick_pow(5,n,100));
	}
	return 0;
}