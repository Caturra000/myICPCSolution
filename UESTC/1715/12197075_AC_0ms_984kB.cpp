#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+11;
typedef long long ll;
ll extend_gcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	extend_gcd(b,a%b,x,y);
	ll tmp=x;
	x=y;
	y=tmp-(a/b)*y;
}
int a[maxn],m[maxn],b[maxn];
ll CRT(int n){
	ll M = 1;
	ll ans = 0;
	for(int i = 1; i <= n; i++) M*=m[i];
	for(int i = 1; i <= n; i++){
		ll Mi = M/m[i];
		ll x,y;
		ll test=extend_gcd(Mi,m[i],x,y);
//		cout<<"test"<<test<<endl;
		ans=(ans+Mi*x*b[i])%M;
	}
	int Max=0;
	for(int i = 1; i <= n; i++) Max=max(Max,a[i]);
	while(ans<Max) ans+=M;
//	cout<<M<<endl;
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	while(cin>>m[1]){
		for(int i = 2; i <= 6; i++)cin>>m[i];
		for(int i = 1; i <= 6; i++){
			cin>>a[i];
			b[i]=a[i]%m[i];
		}
		cout<<CRT(6)<<endl;
	}
	return 0;
}