#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[110003][15];
int a[110003][15];
int main(){
	ios::sync_with_stdio(false); 
	int n,t,x,mmax;
	while(cin>>n){
		if(n==0) break;
		mmax = 0;
		memset(a,0,sizeof a);
		memset(dp,0,sizeof dp);
		for(int i = 1; i <= n; i++){
			cin >> x >> t;
			a[t][x]++;
			mmax = max(mmax,t);
		}			
		for(int i = mmax; i >= 0; i--){
			for(int j = 0; j <= 10; j++){
				if(i==mmax) dp[i][j] = a[i][j];//init
				dp[i][j] = max(dp[i+1][j],j-1<0?dp[i+1][j+1]:max(dp[i+1][j-1],j+1>=11?0:dp[i+1][j+1]))+a[i][j];
            }
		}
		cout << dp[0][5] << endl;
	}
	return 0;
}