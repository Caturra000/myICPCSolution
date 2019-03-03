#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 150;
const int INF = 0x3f3f3f3f;
char str[100];
struct edge{
	int to,cost;
}; 
int T,N,from,n,m,to,cost,x,ans; 
int d[maxn][maxn];
void floyd(){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(d,0,sizeof d);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j < i; j++){
				scanf("%s",str);
				if(str[0]!='x')
					d[i][j] = d[j][i] = atoi(str);
				else
					d[i][j] = d[j][i] = INF;
			}
		}
		floyd();
		int ans = 0;
		for(int i = 1; i <= n; i++) ans = max(ans,d[1][i]);
		printf("%d\n",ans);
	} 
	return 0;
} 