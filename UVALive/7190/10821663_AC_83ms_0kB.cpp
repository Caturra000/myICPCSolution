#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int inf=2*(1e9);
int dp[3000],f[3000];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) dp[i]=-inf;
		for(int i=1;i<n;i++) scanf("%d",&f[i]);
		for(int i=2;i<n;i++){
			for(int j=1;j<=n-2;j++){
				if(j>=i-1){
					dp[j]=max(dp[j],dp[j-i+1]+f[i]-f[1]);
				}
			}
		}
		printf("%d\n",dp[n-2]+n*f[1]);
	}
} 