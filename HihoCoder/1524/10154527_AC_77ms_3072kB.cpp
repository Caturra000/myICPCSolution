#include<cstdio>
#include<cstring>
#define lowbit(b) (b)&(-b)
const int maxn = 100010;
typedef long long ll;
ll ft[maxn],a[maxn];
ll rsq(ll b){
	ll sum = 0;
	while(b){
		sum+=ft[b];
		b-=lowbit(b);
	}
	return sum;
}
void update(ll k,ll v){
	while(k<maxn){
		ft[k]+=v;
		k+=lowbit(k);
	}
}
int main(){
	ll n;
	while(scanf("%lld",&n)!=EOF){
		memset(ft,0,sizeof ft);
		for(int i = 1; i <= n; i++){
			scanf("%lld",&a[i]);  a[i]++; 
		}
		long long ans = 0;
		for(int i = n; i >= 1; i--){
			ans += rsq(a[i]-1);
			update(a[i],1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}