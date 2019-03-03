#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6+11;
const int oo = 0x3f3f3f3f;
typedef long long ll; 
vector<int> G[maxn];
ll dp[maxn];
#define rep(i,j,k) for(int i=j;i<=k;i++)
int main(){
	int n,m,uu,vv;
	while(scanf("%d%d",&n,&m)!=EOF){
		rep(i,0,n) G[i].clear();
		rep(i,1,m){
			scanf("%d%d",&uu,&vv);
			G[uu].push_back(vv);
			G[vv].push_back(uu);
		}
		ll ans=-oo;
		rep(u,0,n)dp[u]=1;
		rep(u,1,n){
			for(int i = 0; i < G[u].size(); i++){//dont use rep
				int v=G[u][i];
				if(u>v)dp[u]=max(dp[u],dp[v]+1);//longest path
			}
		}
		rep(u,1,n){
			ll cnt=G[u].size();
			ans=max(ans,dp[u]*cnt);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}