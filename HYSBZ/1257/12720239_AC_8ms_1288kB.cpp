#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k;
	while(cin>>n>>k){
		long long ans=n*k,gx;
		for(int x=1; x<=n; x=gx+1){
			if(k/x==0)gx=n;
			else gx=min(k/(k/x),n);
			ans -= (long long)((k/x) * (x+gx)*(gx-x+1)/2);
		}
		cout<<ans<<endl;
	}
	return 0;
}