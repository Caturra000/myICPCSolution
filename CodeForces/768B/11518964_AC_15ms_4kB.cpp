#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
typedef unsigned long long ll;
ll query(ll n,ll l,ll r,ll L,ll R){
	if(L>r||R<l)return 0;
	if(n==0)return 0;
	if(n==1)return 1;
	if(L<=l&&r<=R) return n;
	ll m=l+r>>1;
	return query(n/2,l,m-1,L,R)+query(n%2,m,m,L,R)+query(n/2,m+1,r,L,R);
}
int main(){
	ll n,l,r,m;
	ios::sync_with_stdio(0);
	while(cin>>n>>l>>r){
		m=1ll<<((int)log2(n)+1); m--;
		cout<<query(n,1,m,l,r)<<endl;
	}
	return 0;
}