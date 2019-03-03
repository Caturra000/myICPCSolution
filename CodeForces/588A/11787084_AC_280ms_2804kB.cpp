#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
int a[maxn],p[maxn],n;
int main(){
	while(cin>>n){
		for(int i = 1; i <= n; i++) cin>>a[i]>>p[i];
		int mn=0x3f3f3f3f;
		int ans=0;
		for(int i = 1; i <= n; i++){
			mn=min(mn,p[i]);
			ans+=mn*a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}