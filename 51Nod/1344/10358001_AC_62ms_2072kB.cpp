#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,sum,mmin,t;
int main(){
	while(scanf("%lld",&n)!=EOF){
		sum=0;mmin=0;
		for(int i = 0; i < n; i++){
			scanf("%lld",&t);
			sum+=t;
			mmin=min(mmin,sum);
		}
		printf("%lld\n",-mmin);
	}
	return 0;
}