#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[10005];
int dp[10005];
int main(){
	ios::sync_with_stdio(false);
	int k;
	while(cin>>k){
		if(k==0) break;
		int neg=0;
		for(int i = 1; i <= k; i++){
			cin>>a[i];
			if(a[i]<0) neg++;
		}
		if(neg==k){
			cout<<0<<" "<<a[1]<<" "<<a[k]<<endl;
			continue;
		}
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
		for(s = e; cnt != maxx; cnt+=a[--s]);
		cout << maxx << " " << a[s] << " " << a[e] << endl;
	}
	return 0;
}