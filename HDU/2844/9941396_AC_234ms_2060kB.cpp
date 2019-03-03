#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 123,M = 100006;
int n,m;
int a[maxn],c[maxn]; 
//int dp[maxn][maxnn];//凑满j时留下的最多的i类硬币 
int dp[M]; //M最大能到达的数 
//参考背包九讲
 
void ZeroOnePack(int cost,int value,int sz){//cost value size 
	for(int j = sz; j >= cost; j--)
		dp[j] = max(dp[j],dp[j-cost]+value);
}
void CompletePack(int cost,int value,int sz){
	for(int j = cost; j <= sz; j++)
		dp[j] = max(dp[j],dp[j-cost]+value);
}
void MultiPack(int cost,int value,int sz,int num){
	if(num*cost>sz) CompletePack(cost,value,sz);
	else{
		int k = 1;
		while(k < num){
			ZeroOnePack(k*cost,k*value,sz);
			num -= k;
			k <<= 1;
		}
		ZeroOnePack(num*cost,num*value,sz);
	}
}


int main(){
//	ios::sync_with_stdio(false);
	while(scanf("%d%d",&n,&m) && n+m){
		for(int i = 1; i <= n; i++){
			scanf("%d",&a[i]);
		}
		for(int i = 1; i <= n; i++){
			scanf("%d",&c[i]);
		}
		memset(dp,0,sizeof dp);
//		for(int i = 1; i <= n; i++){
//			for(int j = 0; j <= m; j++){
//				if(dp[i-1][j]>=0) dp[i][j] = c[i];
//				else dp[i][j] = -1; //异议 
//			}
//			for(int j = 0; j <= m-a[i]; j++){
//				if(dp[i][j]>=0) dp[i][j+a[i]] = max(dp[i][j]-1,dp[i][j+a[i]]);
//			}
//		}
		for(int i = 1; i <= n; i++){
			MultiPack(a[i],a[i],m,c[i]); //NOTE cost == value == ai?
		}
		int tot = 0;
		for(int i = 1; i <= m; i++)
//			cout << "dp[" << i << " ] = " << dp[i] << endl;
			if(dp[i]==i) tot++;  //NOTE == ? cost == maxvalue
		printf("%d\n",tot);
	}
	return 0;
}