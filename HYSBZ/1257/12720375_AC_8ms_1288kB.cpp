#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,k,ans,gx,l,r,w,val;
	while(cin>>n>>k){
		ans=n*k;
		for(int x=1; x<=n; x=gx+1){
			val=k/x;
			if(val==0) break;
			gx=min(k/(k/x),n);
			l=x,r=gx;
			w=r-l+1;
			ans -= val*(l+r)*w/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}