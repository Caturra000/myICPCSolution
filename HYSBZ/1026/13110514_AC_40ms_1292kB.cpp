#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
using namespace std;
const int maxn = 23;
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
//		if(abs(pre-i)>=2||st) ans+=DP(cur-1,0,i,limit&&a[cur]==i); 

//		if(st&&i==0) ans+=DP(cur-1,st,i,limit&&a[cur]==i);
		ans+=DP(cur-1,st&&i==0,i,limit&&a[cur]==i); 
//		if(abs(pre-i)<2)continue;
//		if(st&&i==0) ans+=DP(cur-1,st,i,limit&&a[cur]==i);
//		else ans+=DP(cur-1,st&&i==0,i,limit&&a[cur]==i);
	}
	return (limit||st)?ans:dp[cur][pre]=ans;
//	return (limit||st)?ans:dp[cur][st][pre]=ans;
}
ll solve(ll num){
	memset(dp,-1,sizeof dp);
	int cur=0;
	while(num){
		a[++cur]=num%10;
		num/=10; 
	}
	return DP(cur,1,1212,1);
}
int main(){
	
	while(~scanf("%lld%lld",&l,&r)){
		printf("%lld\n",solve(r)-solve(l-1));
	}
	return 0;
}