#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int maxn = 1e6+11;
typedef unsigned long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
int n;
int main(){
	while(cin>>n){
		ll ans=0;
		int Limit=max(1,n-50);
		rrep(i,n,Limit){
			rrep(j,n,Limit){
				rrep(k,n,Limit){
					ans=max(ans,lcm(lcm(i,j),k));
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}