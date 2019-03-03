#include<bits/stdc++.h>
using namespace std;
const int maxn = 2030;
bool P[maxn][maxn],Q[maxn][maxn];
vector<int> p[maxn],q[maxn];
char str[maxn];
int n;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(P,0,sizeof P);
		memset(Q,0,sizeof Q);
		for(int i = 0; i <= n; i++) p[i].clear(),q[i].clear();
		for(int i = 1; i <= n; i++){
			scanf("%s",str+1);
			for(int j = 1; j <= n; j++){
				if(str[j]=='P'){
					P[i][j]=1;
					p[i].push_back(j);
				}
				else if(str[j]=='Q'){
					Q[i][j]=1;
					q[i].push_back(j);
				}
			}
		}
		
		bool flag=0;
		
		for(int i = 1; i <= n; i++){
			int u = i;
			for(int j = 0; j < p[i].size(); j++){
				int v = p[u][j];
				if(p[v].size()==0)continue;
				for(int k = 0; k < p[v].size(); k++){
					int w = p[v][k];
					if(P[u][w]==0){
						flag=1;
						break;
					}
				}
				if(flag)break;
			}
			if(flag)break;
		}
		
		if(flag){
			printf("N\n");
			continue;
		}
		
		for(int i = 1; i <= n; i++){
			int u = i;
			for(int j = 0; j < q[i].size(); j++){
				int v = q[u][j];
				if(q[v].size()==0)continue;
				for(int k = 0; k < q[v].size(); k++){
					int w = q[v][k];
					if(Q[u][w]==0){
						flag=1;
						break;
					}
				}
				if(flag)break;
			}
			if(flag)break;
		}//cout<<"weWEW";
		if(flag) printf("N\n");
		else printf("T\n");
	}
	return 0;
} 