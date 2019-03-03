#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll INF = 1ll<<62,maxn=100110;
ll dp[maxn][2],a,n;
int main(){
	while(scanf("%lld",&n)!=EOF){
		for(int i = 0; i < maxn; i++){
			dp[i][0]=-INF;dp[i][1]=-INF;
		}
		for(int i = 1; i <= n; i++){
			scanf("%lld",&a);//a=a&1;cout<<a;
			if(a%2){
				dp[i][0]=max(dp[i-1][0],dp[i-1][1]+a);
				dp[i][1]=max(a,max(dp[i-1][1],dp[i-1][0]+a));
			}
			else{
				dp[i][0]=max(a,max(dp[i-1][0],dp[i-1][0]+a));
				dp[i][1]=max(dp[i-1][1],dp[i-1][1]+a);
			}
		}
		printf("%lld\n",dp[n][1]);
	}
	return 0;
}