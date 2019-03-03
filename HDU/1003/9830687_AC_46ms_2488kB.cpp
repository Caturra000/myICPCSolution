#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005];
int dp[100005];
int main(){
	ios::sync_with_stdio(false);
	int T,T2,k,kase=0;cin >> T;T2=T;
	while(T--){
		cin>>k;
		if(k==0) break;
		int neg=0;
		for(int i = 1; i <= k; i++)
			cin>>a[i];
		int s=0,e=0;
		//solve
		long long maxx = -99999999; 
		for(int i = 1; i <= k; i++){
			dp[i] = max(dp[i-1]+a[i],a[i]);//拿或另取 
			if(dp[i] > maxx){
				maxx = dp[i];
				e = i;
			}
		}
		long long cnt = a[e];
		int mark = e;
		for(s = e; s!=0; cnt+=a[--s])
			if(cnt==maxx) mark = s;
		if(T2!=1 && (T!=0))	
			cout << "Case " << ++kase << ":\n" << maxx << " " << mark << " " << e << "\n\n";
		else
			cout << "Case " << ++kase << ":\n" << maxx << " " << mark << " " << e << "\n";
	}
	return 0;
}