#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+1e2; 
typedef long long ll;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);} 
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
ll n,m,z;
int main(){
	while(scanf("%lld%lld%lld",&n,&m,&z)!=EOF){
		printf("%lld\n",z/lcm(n,m));
	}
	return 0;
}