#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
int a[maxn],b[maxn],boy,girl;
int main(){
	while(cin>>boy){
		for(int i = 1; i <= boy; i++) cin>>a[i];
		cin>>girl;
		for(int i = 1; i <= girl; i++) cin>>b[i];
		sort(a+1,a+boy+1);sort(b+1,b+girl+1);
		int pos=1,ans=0;
		if(boy<girl){
			for(int i = 1; i <= boy; i++){
				for(int j= pos; j <= girl; j++){
					if(abs(a[i]-b[j])<=1){
						ans++;pos=j+1;
						break;
					}
				}
			}
		}
		else{
			for(int i = 1; i <= girl; i++){
				for(int j= pos; j <= boy; j++){
					if(abs(b[i]-a[j])<=1){
						ans++;pos=j+1;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}