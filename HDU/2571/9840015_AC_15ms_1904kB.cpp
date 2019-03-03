#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int map[25][1005];
int dp[25][1005];
int main(){
	ios::sync_with_stdio(false);
	int C; cin >> C;
	while(C--){
		memset(map,0,sizeof map);
		memset(dp,0x80,sizeof dp);//注意负数的更新 
		int n,m; cin >> n >> m;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> map[i][j];
				//dp[i][j] = map[i][j];
			}
		}
		dp[1][1] = map[1][1];
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(j+1<=m&&dp[i][j]+map[i][j+1]>dp[i][j+1]){
					dp[i][j+1] = dp[i][j]+map[i][j+1];
				}
				if(i+1<=n&&dp[i][j]+map[i+1][j]>dp[i+1][j]){
					dp[i+1][j] = dp[i][j]+map[i+1][j];
				}
				for(int k = 2*j; k <= m; k+=j){
					if(dp[i][j]+map[i][k]>dp[i][k]){
						dp[i][k] = dp[i][j]+map[i][k];
					}
				}
			}
		}
		
//		for(int i = 1; i <= n; i++){
//			cout << endl;
//			for(int j = 1; j <= m; j++){
//				cout << dp[i][j] << " ";
//			}
//		}
		cout << dp[n][m] << endl;
	} 
	return 0; 
} 