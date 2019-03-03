#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define scan(a) scanf("%d",&a)
using namespace std;
const int maxn = 5e5+11;
const int oo = 0x3f3f3f3f;
int n,m,K;
typedef pair<int,int> P;
vector<P> vec[16];
int dp[2][maxn];
int main(){
	while(scanf("%d%d%d",&n,&m,&K)!=EOF){
		rep(i,1,K) vec[i].clear();
		rep(i,1,n){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			vec[a].push_back(P(b,c)); 
		}
		bool flag=0;
		rep(i,1,K) if(!vec[i].size()) flag=1;
		if(flag){
			printf("Impossible\n");
			continue;
		}
		rep(i,0,m) dp[0][i]=0;
		rep(i,1,K){
			memset(dp[i&1],0x80,sizeof dp[i&1]); //滚动时注意 
			for(auto k:vec[i]){
				rrep(j,m,k.first){
					int c=k.first,w=k.second;
					dp[i&1][j]=max(dp[i&1][j],max(dp[i&1][j-c]+w,dp[i-1&1][j-c]+w));
				}
			}
		}
		if(dp[K&1][m]<0) printf("Impossible\n");
		else printf("%d\n",dp[K&1][m]);
	}
	return 0;
} 