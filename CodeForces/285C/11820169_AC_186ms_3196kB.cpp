#include<bits/stdc++.h>
using namespace std;
const int maxn =  3e5+11;
typedef long long ll;
int a[maxn],n;
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		ll sum=0;
		for(int i = 1; i<=n; i++) sum+=abs(i-a[i]);
		printf("%lld\n",sum);
	}
	return 0;
} 