#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
#define rep(i,j,k) for(int i=j;i<=k;i++)

typedef long long ll;
ll n,m,a[maxn],b[maxn],vis[maxn];
stack<ll> stk,s;
ll go(ll x){
	stack<ll> stk2;
	ll ans=0;
	while(stk.top()!=x){
		stk2.push(stk.top());
		ans+=a[stk.top()];
		stk.pop();
	}
	int t=stk.top();stk.pop();
	while(stk2.size()){
		stk.push(stk2.top());
		stk2.pop();
	}
	stk.push(t);
	return ans;
}
int main(){
	while(cin>>n>>m){
		while(s.size()) s.pop();
		while(stk.size()) stk.pop();
		memset(vis,0,sizeof vis);
		rep(i,1,n)cin>>a[i];
		rep(i,1,m)cin>>b[i];
		rep(i,1,m){
			if(!vis[b[i]]){
				s.push(b[i]);
				vis[b[i]]=1;
			}
		}
		while(s.size()){
			stk.push(s.top());
			s.pop();
		}
		ll ans=0;
		rep(i,1,m){
			ans+=go(b[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}