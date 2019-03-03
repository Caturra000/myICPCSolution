#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
const int maxn = 1e6+7;
int n,a[maxn],cnt,t,mmax;
int main(){
	ios::sync_with_stdio(false);
	while(cin>>n){
		memset(a,0,sizeof a);mmax = 0; 
		for(int i = 0; i < n; i++){
			cin>>t;
			a[t]++;
			mmax=max(mmax,t);
		}
		for(int i = mmax; i >= 1; i--){
			cnt=0;
			for(int j = i; j <= mmax; j+=i){
				if(a[j]) cnt++;
			}
			if(cnt>1){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}