#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[1010],a[1010],n,ans;
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i = 1; i <= n; i++){
			scanf("%d",&a[i]);
		}
		memset(dp,INF,sizeof dp);
		for(int i = 1;i <= n ;i++){
			*lower_bound(dp+1,dp+n+1,a[i]) = a[i]; 
		}
		printf("%d\n",lower_bound(dp+1,dp+n+1,INF)-(dp+1));
	}
	return 0;
}