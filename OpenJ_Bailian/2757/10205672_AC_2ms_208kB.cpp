#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn =1010;
int dp[maxn],a[maxn],n,ans;
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i = 0; i < n; i++){
			scanf("%d",&a[i]);
		}
		for(int i = 0; i < n; i++) dp[i] = 1;
		for(int i = 1; i < n; i++){
			for(int j = 0; j < i; j++){
				if(a[i]>a[j]) dp[i] = max(dp[i],dp[j]+1);
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++) ans = max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
} 