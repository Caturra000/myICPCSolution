#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,k;
	while(cin>>n>>k){
		if(k==1)cout<<n<<endl;
		else{
			ll pos;
			for(int i=63;i>=0;i--){
				if((n>>i)&1){
					pos=i;
					break;
				}
			}
			cout<<(1ll<<pos+1)-1<<endl;
		}
	}
	return 0;
}