#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+11;
int a[maxn],n,k;
int main(){
	while(cin>>n>>k){
		for(int i = 1; i <= n; i++) cin>>a[i];
		long long ans=0;
		for(int i = 2; i <= n; i++){
			if(a[i]+a[i-1]<k){
				ans+=k-a[i-1]-a[i];
				a[i]=k-a[i-1];
			}
		}
		cout<<ans<<endl;
		for(int i = 1; i <= n; i++){
			if(i==n) cout<<a[i]<<endl;
			else cout<<a[i]<<" ";
		}
	}
	return 0;
}