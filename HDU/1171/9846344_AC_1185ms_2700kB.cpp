#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int v[5006];
int dp[250003];
int main(){
	ios::sync_with_stdio(false);
	int n;
	while(cin >> n){
		if(n<0) break;
		int av=0,sm,in,inn,k=0;//DIE1
		memset(v,0,sizeof v);
		for(int i = 1; i <= n; i++){
			cin >> in >> inn;
			av += in*inn;
			for(int j = 0; j < inn; j++){
				v[++k] = in;
			}
		}
		//cout << av << endl;
		sm=av; av/=2;
		memset(dp,0,sizeof dp);
		for(int i = 1; i <= k; i++) //DIE2 n k 
			for(int j = av; j >= v[i]; j--)
					dp[j] = max(dp[j],dp[j-v[i]]+v[i]);
					
		cout << sm-dp[av] << " " <<dp[av] << endl;
	}
	return 0;
}