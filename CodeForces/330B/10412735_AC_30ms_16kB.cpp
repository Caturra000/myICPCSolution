#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool vis[11000]; 
int now,from,to,n,m;
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(vis,0,sizeof vis);
		for(int i = 0; i < m; i++){
			scanf("%d%d",&from,&to);
			vis[from]=1;vis[to]=1;
		}
		for(int i = 1; i <= n; i++){
			if(!vis[i]){
				now=i;break;
			}
		}
		printf("%d\n",n-1); 
		for(int i = 1; i <= n; i++){
			if(i==now) continue;
			printf("%d %d\n",now,i);
		}
	}
	return 0;
} 