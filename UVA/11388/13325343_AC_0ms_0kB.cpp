#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
typedef long long ll;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int main(){
	int T; cin>>T;
	while(T--){
		int G,L; cin>>G>>L;
		if(gcd(G,L)!=G) cout<<-1<<endl;
		else cout<<G<<" "<<L<<endl;
	}
	return 0;
}