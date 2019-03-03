#include<bits/stdc++.h>
#define rep(i,j,k) for(int i = j; i <=k; i++)
using namespace std;
const int maxn = 55;
typedef long long ll;
ll one[maxn];
ll n;
ll dfs(ll n,ll i){
	ll k = n/one[i];
	ll j = n%one[i];
	if(j==0) return k*i;
	return k*i+min(i+dfs(one[i]-j,i-1),dfs(j,i-1));
}
int main(){
	one[0]=0;
	rep(i,1,16) one[i]=10*one[i-1]+1;
	while(cin>>n) cout<<dfs(n,16)<<endl;
	return 0;
} 