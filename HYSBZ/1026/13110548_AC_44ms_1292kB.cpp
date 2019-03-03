#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
using namespace std;
const int maxn = 20;
typedef long long ll;
int a[maxn];
ll l,r,dp[maxn][15];

ll DP(int cur,int st,int pre,int limit){
	if(cur==0) return 1;
	if(!st&&!limit&&dp[cur][pre]!=-1)return dp[cur][pre];
	int up=limit?a[cur]:9;
	ll ans=0;
	rep(i,0,up){
		if(!st&&abs(pre-i)<2)continue;
		ans+=DP(cur-1,st&&i==0,i,limit&&a[cur]==i);
	}
	return (limit||st)?ans:dp[cur][pre]=ans;
}
ll solve(ll num){
	
	int cur=0;
	while(num){
		a[++cur]=num%10;
		num/=10; 
	}
	return DP(cur,1,1212,1);
}
int main(){
	memset(dp,-1,sizeof dp);
	while(~scanf("%lld%lld",&l,&r)){
		printf("%lld\n",solve(r)-solve(l-1));
	}
	return 0;
}