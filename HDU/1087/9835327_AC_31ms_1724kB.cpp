#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long a[1003];
long long sz,dp[1003];

int main(){
	ios::sync_with_stdio(false);
	int n,t;
	while(cin>>n){
		if(n==0) break;
		memset(dp,-1,sizeof dp);
		memset(a,0,sizeof a);
		a[0] = 0;//start 
		sz = 1;
		for(int i = 1; i <= n; i++){
			cin >> t;
			//if(m[t]==0) a[sz++]=t; 
			a[sz++]=t; 
			//m[t]++;
		}
		long long ans = 0;
		for(int i = 1; i < sz; i++){
			dp[i] = a[i];
			for(int j = 1; j < i; j++){
				if(a[i]>a[j] && dp[i]<dp[j]+a[i]){ //NOTE:a[j]<a[i] 区别于a[i-1]<a[i] ↓错误策略 //全局最优 
					dp[i] = dp[j]+a[i];
				}
			}
			
			//if(i==1) dp[i] = a[i];
			//else if(a[i-1]<a[i]) dp[i] = max(a[i],max(dp[i-1]+a[i],dp[i]));//重新开始 继承or跳过 
			//else dp[i] = max(dp[i-1],a[i]);//不选跳过 重新开始 
		}
		for(int i = 1; i < sz; i++) ans = max(ans,dp[i]);
		//cout << dp[sz-1] << endl; 
		cout << ans << endl;
	}	
	return 0;
} 