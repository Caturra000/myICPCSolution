#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e2;
bool dp[maxn][maxn];
int M,C,g[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--){
		memset(dp,0,sizeof dp);
		cin>>M>>C;
		for(int i = 0; i < C; i++){
			cin>>g[i][0];
			for(int j = 1; j <= g[i][0]; j++){
				cin>>g[i][j];
			}
		}
		for(int i = 1; i <= g[0][0]; i++) if(M-g[0][i]>=0) dp[0][M-g[0][i]]=1;
		
		for(int i = 1; i < C; i++){
			for(int j = M; j >= 0; j--){
				if(dp[i-1][j]){
					for(int k = 1; k <= g[i][0]; k++){
						if(j-g[i][k]>=0){
							dp[i][j-g[i][k]] = 1;
						}
					}
				}
			}
		}
		for(int i = 0; i <= M; i++){
			if(dp[C-1][i]){
				printf("%d\n",M-i);
				break;
			}
			if(i==M){
				printf("no solution\n");
				break;
			}
		}
	}
	return 0;
} 