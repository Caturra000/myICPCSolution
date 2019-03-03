#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 233;
ll n,cnt;
ll prime[maxn],num[maxn];
void chai(ll a){
	cnt=0;
	memset(num,0,sizeof num);
	memset(prime,0,sizeof prime);
	for(ll i = 2; i*i <= a; i++){
		if(cnt>2) break;
		if(a%i==0){
			cnt++;
			prime[cnt]=i;num[cnt]++;
			a/=i;
			while(a%i==0){
				num[cnt]++;
				a/=i;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	while(cin>>n){
		chai(n);
		if((cnt>=2)||(cnt==1&&num[cnt]>=2)||cnt==0){
			if(cnt==1&&num[cnt]==2&&n==prime[cnt]*prime[cnt]){
				cout<<2<<endl;
				continue; 
			}
			cout<<1<<endl;
			if(cnt==0) cout<<0<<endl;
			else if(num[1]>1) cout<<prime[1]*prime[1]<<endl;
			else cout<<prime[1]*prime[2]<<endl;
		}
		else cout<<2<<endl;
	}
}