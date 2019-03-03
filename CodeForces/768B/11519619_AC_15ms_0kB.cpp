#include<cstdio>
#include<cmath>
typedef long long ll;
ll query(ll n,ll l,ll r,ll L,ll R){
	if(L>r||R<l)return 0;
	if(L<=l&&r<=R) return n;
	ll m=l+r>>1;
	return query(n/2,l,m-1,L,R)+query(n%2,m,m,L,R)+query(n/2,m+1,r,L,R);
}
int main(){
	ll n,l,r,m;
	while(scanf("%I64d%I64d%I64d",&n,&l,&r)!=EOF){
		m=1ll<<((int)log2(n)+1); m--;
		printf("%I64d\n",query(n,1,m,l,r));
	}
	return 0;
}