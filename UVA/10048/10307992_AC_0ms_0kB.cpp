#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 211,INF = 0x3f3f3f3f;
int d[maxn][maxn];
int n,m,q,id,od,ans,from,to,cnt,flag,kase,cost;
void floyd(){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++) if(i!=j)
				d[i][j] = min(d[i][j],max(d[i][k],d[k][j]));//最大噪音最小 
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	while(cin>>n>>m>>q){
		if(n==0) break;
		if(kase) cout<<endl;
		memset(d,INF,sizeof d);
		for(int i = 0; i < m; i++){
			cin>>from>>to>>cost;
			d[from][to]=cost;
			d[to][from]=cost;//NOTE
		}
		floyd();flag=0;
		for(int i = 0; i < q; i++){
			cin>>from>>to;
			if(!flag){
				flag=1;cout<<"Case #"<<++kase<<endl;
			}
			if(d[from][to]!=INF) cout<<d[from][to]<<endl;
			else cout<<"no path"<<endl;
			//if(i==q-1) cout<<endl;
		}
	}
	return 0;
}