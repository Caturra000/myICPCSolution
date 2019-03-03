#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+11;
const long long oo = 1ll<<62; 
typedef long long ll;
ll a[maxn],n,m;
bool C(ll x){
	ll tmp=0,cnt=0;
	for(int i = 0; i < n; i++){
		if(x<a[i]) return 0;
		if(i==n-1){
			if(tmp+a[i]<=x) cnt++;
			else cnt+=2;
		}
		else if(tmp+a[i]<=x){
			tmp+=a[i];
		} 
		else{
			tmp=a[i];cnt++;
		}
	}
	return cnt>m?0:1;
}
int main(){
	while(scanf("%lld%lld",&n,&m)!=EOF){
		ll low=0,sum=0;
		for(int i = 0; i < n; i++){
			scanf("%lld",&a[i]); 
			low=max(low,a[i]);
			sum+=a[i];
		}
		ll l=low,r=sum,mid;
		while(l<r){
			mid=l+r>>1;
			if(C(mid)) r=mid;
			else l=mid+1;
		}
		printf("%lld\n",l);
	}
	return 0;
}