#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
typedef unsigned long long ll;
ll fib[233],n;
int main(){
	fib[1]=1;fib[2]=2;
	int now=2;
	while(fib[now]<=4ll*ll(10000000000000000)){
		fib[now+1]=fib[now-1]+fib[now];
		now++;
	}now--;
	int T; scanf("%d",&T);
	while(T--){
		scanf("%llu",&n);
		ll ans=0;
		int cnt=2;
		while(fib[cnt]%2==0&&fib[cnt]<=n&&cnt<=now){
			ans+=fib[cnt];
			cnt+=3;
		}
		printf("%llu\n",ans);
	}
	return 0;
}