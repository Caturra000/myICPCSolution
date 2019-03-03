#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
string str;
int dp[506][4]; // 第几个 正常打/按shift/lock/
bool diff(char a,char b){
	if(a>='a' && a <= 'z'){
		if(b >='a'&&b<='z')
			return false;
		else
			return true;
	}
	else{
		if(b >='a'&&b<='z')
			return true;
		else
			return false;
	}
}
int main(){
	ios::sync_with_stdio(false);
	int T; cin>>T; 
	while(T--){
		cin >> str; str+='a';//用于处理末尾Lock问题 
		int len = str.length();
		memset(dp,0x3f3f3f3f,sizeof dp);
		diff('a',str[0])?dp[1][1]=2,dp[1][2]=2/*dp[1][3]=777777*/:dp[1][0]=1;
		for(int i = 2; i <= len; i++){
			if(diff(str[i-2],str[i-1])){//小写变大写 大写变小写 
				dp[i][0] = min(dp[i][0],dp[i-1][1]+1);//正常打 :从上一步shift的+1 
				dp[i][1] = min(dp[i-1][0]+2,dp[i-1][2]+2);//shifts
				dp[i][2] = min(dp[i-1][0]+2,dp[i-1][2]+2);//lock
			}
			else{
				dp[i][0] = min(dp[i-1][0]+1,dp[i-1][2]+1);
				dp[i][1] = min(dp[i-1][1]+2,dp[i-1][2]+2);
				dp[i][2] = min(dp[i][2],dp[i-1][1]+2); 
			}
		}
		int ans = min(dp[len][0],min(dp[len][1],dp[len][2])); 
		cout << ans-1 << endl; 
	}
	return 0;
} 