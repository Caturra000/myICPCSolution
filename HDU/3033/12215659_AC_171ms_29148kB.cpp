#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define scan(a) scanf("%d",&a)
using namespace std;
const int maxn = 5e5+11;
const int oo = 0x3f3f3f3f;
int n,m,K;
typedef pair<int,int> P;
vector<P> vec[666];
int dp[14][maxn];
int main(){
	ios::sync_with_stdio(0);
	while(cin>>n>>m>>K){
		rep(i,1,K) vec[i].clear();
		rep(i,1,n){
			int a,b,c;
			cin>>a>>b>>c;
			vec[a].push_back(P(b,c)); 
		}
		bool flag=0;
		rep(i,1,K) if(!vec[i].size()) flag=1;
		if(flag){
			cout<<"Impossible"<<endl;
			continue;
		}
		memset(dp,0x80,sizeof dp);
		rep(i,0,m) dp[0][i]=0;
		rep(i,1,K){
			for(auto k:vec[i]){
				rrep(j,m,k.first){
					int c=k.first,w=k.second;
					dp[i][j]=max(dp[i][j],max(dp[i][j-c]+w,dp[i-1][j-c]+w));
				}
			}
		}
		if(dp[K][m]<0) cout<<"Impossible"<<endl;
		else cout<<dp[K][m]<<endl; 
	}
	return 0;
} 