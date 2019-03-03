#include<cstdio>
#include<cstring>
char map[24][24];
int T,ans,n,k,row[24],col[24];
void backtrack(int cur,int x,int y){
	if(cur==k){
		ans++;
	}
	else{
		for(int i = x+1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(map[i][j] == '#' && row[i]==0 && col[j]==0){
					row[i] = 1; col[j] = 1;
					backtrack(cur+1,i,j); 
					row[i] = 0; col[j] = 0;
				}
			}
		}
	}
}
int main(){
	while(scanf("%d %d",&n,&k)==2){
		if(n==-1) break;
		memset(map,0,sizeof map);
		for(int i = 1; i <= n; i++){
			//for(int j = 1; j <= n; j++){
				scanf("%s",map[i]+1);
			//}
		}
		ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(map[i][j]=='#'){
					memset(row,0,sizeof row); memset(col,0,sizeof col);
					row[i] = 1; col[j] = 1;
					backtrack(1,i,j);//第一个已经放好且不会重复 
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 