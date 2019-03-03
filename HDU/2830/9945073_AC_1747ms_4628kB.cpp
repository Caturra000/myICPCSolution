#include<bits/stdc++.h>
using namespace std;
const int maxn = 3000;
char g[maxn][maxn]; 
int h[maxn],th[maxn];
bool cmp(int a,int b){return a>b;}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		//memset(h,0,sizeof h); 
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				scanf(" %c",&g[i][j]);//空格 
				if(g[i][j]=='1'){
					h[j]++;
				}
				else{
					h[j] = 0;
				}
				th[j] = h[j];
			}
			sort(th+1,th+1+m,cmp);
			for(int j = 1; j <= m && th[j]!=0; j++)
				ans = max(ans,th[j]*j);
		}
		printf("%d\n",ans);
	}
	return 0;
}