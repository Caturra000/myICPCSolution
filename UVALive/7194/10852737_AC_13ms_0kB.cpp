#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;
int G[maxn][maxn];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0}; 
int main(){
	ios::sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int i,j,k,n,m;cin>>n>>m;
		memset(G,0,sizeof G);
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				cin>>G[i][j];
			}
		}
		int ans=0; 
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				if(G[i][j]==0) continue;
				else{
					ans++;
					for(k=0;k<4;k++){
						int now=G[i][j],tmp=G[i+dx[k]][j+dy[k]];
						if(now>tmp) ans+=now-tmp;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 