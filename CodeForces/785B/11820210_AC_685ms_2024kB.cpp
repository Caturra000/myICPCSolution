#include<bits/stdc++.h>
#define rep(i,j,k) for(int i = j; i <= k; i++)
using namespace std;
const int maxn = 1e5+11;
int main(){
	ios::sync_with_stdio(0);
	int n,m,a,l,r;
	while(cin>>n){
		int lmx=0,rmn=1e9+7;
		rep(i,1,n){
			cin>>l>>r;
			lmx=max(l,lmx);
			rmn=min(r,rmn);
		}
		cin>>m;
		int llmx=0,rrmn=1e9+7; 
		rep(i,1,m){
			cin>>l>>r;
			llmx=max(l,llmx);
			rrmn=min(r,rrmn);
		}
		int ans=llmx>=rmn?llmx-rmn:0;
		ans=max(ans,lmx>=rrmn?lmx-rrmn:0);
		cout<<ans<<endl;
	}
	return 0;
}