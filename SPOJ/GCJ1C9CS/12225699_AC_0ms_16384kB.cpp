#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define oo 0x3f3f3f3f
using namespace std;
const int maxn = 233;
int A[maxn],P,Q;
int dp[maxn][maxn];
int main(){
	ios::sync_with_stdio(0);
	int T,kase=0; cin>>T;
	while(T--){
		cin>>P>>Q;
		rep(i,1,Q) cin>>A[i];A[Q+1]=P+1;
		memset(dp,0,sizeof dp);
		rep(w,2,Q+1){//width
			rep(i,0,Q+1-w){//st 
				int j=i+w, t=oo;//ed
				rep(k,i+1,j-1){//release
					t=min(t,dp[i][k]+dp[k][j]);
				}
				dp[i][j]=t+A[j]-A[i]-2;
//				cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			}
		}
		cout<<"Case #"<<++kase<<": "<<dp[0][Q+1]<<endl;
	}
	return 0;
}