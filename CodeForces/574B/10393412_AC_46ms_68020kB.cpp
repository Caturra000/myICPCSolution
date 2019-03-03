#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 4100,INF=0x3f3f3f3f;
int G[maxn][maxn];
vector<int> G2[maxn];
//vector<edge> G2[maxn];
int od[maxn];
int n,m,from,to, dalao;
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(od,0,sizeof od); memset(G,0,sizeof G); memset(G2,0,sizeof G2);
		for(int i = 0 ; i < m; i++){
			scanf("%d%d",&from,&to);
			if(G[from][to]==1||G[to][from]==1||from==to) continue;
			else{
				G2[from].push_back(to);G2[to].push_back(from);
				G[from][to]=1; G[to][from]=1; od[from]++; od[to]++;
			}
		}
		int mmin=INF;
		for(int i = 1; i <= n; i++){
			from = i;
			for(int j = 0; j < G2[from].size(); j++){
				to = G2[from][j];
				for(int k = 0; k < G2[to].size(); k++){
					dalao = G2[to][k];
					if(from!=to&&to!=dalao&&from!=dalao&&G[from][dalao]==1&&G[dalao][from]==1){
//						cout<<"From"<<from<<"To"<<to<<"Dalao"<<dalao<<"OD"<<od[from]+od[to]+od[dalao]-6<<endl;
						mmin=min(mmin,od[from]+od[to]+od[dalao]-6);
					}
				}
			}
		}
//		for(int i = 1; i <= n; i++){
//			for(int j = 0; j < G2[i].size(); j++){
//				for(int k = 1; k <= n; k++){
//					from = i; to = G2[i][j];
//					if(from!=k&&to!=k&&G[from][to]&&G[to][k]&&G[from][k]){
//						mmin=min(mmin,od[from]+od[to]+od[k]-6);
//					}
//				}
//			}
//		}
		
//		for(int i = 1; i <= n; i++){
//			for(int j = i+1; j <= n; j++){
//				for(int k = j+1; k <= n; k++){
//					if(G[i][j]&&G[i][k]&&G[j][k]) mmin=min(mmin,od[i]+od[j]+od[k]-6);
//				}
//			}
//		}
		printf("%d\n",(mmin==INF||mmin<0)?-1:mmin);
	}
	return 0;
}