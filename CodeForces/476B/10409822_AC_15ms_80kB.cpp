#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
const int maxn = 1e5+1e2; 
typedef long long ll;
string str1,str2;
int pos,un,pos2;
double dp[100][100];
int main(){
//	ios::sync_with_stdio(false);
	while(cin>>str1>>str2){
		pos=0;un=0;pos2=0;
		for(int i = 0; i < str1.length(); i++){
			if(str1[i]=='+') pos++;
			else pos--;
		}
//		cout<<pos<<endl;
		for(int i = 0; i < str2.length(); i++){
			if(str2[i]=='?') un++;
			else if(str2[i]=='-') pos2--;
			else pos2++;
		} 
		memset(dp,0,sizeof dp);
		dp[0][pos2+30] = 1.0;
		for(int i = 1; i <= un; i++){
			for(int j = 1; j <= 80; j++){
				dp[i][j]=0.5*dp[i-1][j-1]+0.5*dp[i-1][j+1];
			}
		}
//		cout<<dp[un][pos+30]<<endl;
		printf("%.12lf\n",dp[un][pos+30]);
	}
	return 0;
}