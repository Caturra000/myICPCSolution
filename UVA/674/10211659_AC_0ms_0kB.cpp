#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 10100;
int n,k; 
int a[maxn],dp[8][maxn];//数组过大memset也救不了你 
int dfs(int cur,int k){
	if(k==0) return 1;//满足+1 
	if(k<0) return 0;
	if(cur==n) return 0;//NOTE 满足k已经加1,不满足的自然是0 
	if(dp[cur][k]!=0) return dp[cur][k];//TLE!!!
//	if(dp[cur][k]!=-1) return dp[cur][k]; 
	return dp[cur][k] = dfs(cur+1,k)+dfs(cur,k-a[cur]); 
}
int main(){
//	int T; scanf("%d",&T);
	a[0]=50,a[1]=25,a[2]=10,a[3]=5,a[4]=1,n=5;
//	while(T--){
//		scanf("%d%d",&n,&k);
//		for(int i = 0; i < n; i++){
//			scanf("%d",&a[i]);
//		}
	memset(dp,0,sizeof dp);
	while(scanf("%d",&k)!=EOF){
//		memset(dp,0,sizeof dp); //NOTE
//		memset(dp,-1,sizeof dp);//只需1次 内部循环memset反复求子问题会TLE 
		int ans = dfs(0,k);
		if(!ans&&n) printf("no solution\n");
		else printf("%d\n",ans);
	}
	return 0;
}