#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+11;
typedef long long ll;
ll a[maxn],b[maxn],n;
int main(){
	ios::sync_with_stdio(0);
	while(cin>>n){
		if(n==0) break;
		for(int i = 0; i < n; i++) cin>>a[i];
		for(int i = 0; i < n; i++) cin>>b[i];
		sort(a,a+n);sort(b,b+n);
		int l1=0,r1=n-1,l2=0,r2=n-1;
		ll ans=0;
		for(int i = 0; i < n; i++){
			if(a[l1]>b[l2]){
				l1++;l2++;
				ans+=200;
			}
			else if(a[r1]>b[r2]){
				r1--;r2--;
				ans+=200;
			}
			else if(a[l1]<b[r2]){
				l1++;r2--;
				ans-=200;
			}
			else{
				l1++;r2--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
