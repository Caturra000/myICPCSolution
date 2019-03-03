#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int c[1234][1234];
int dr[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int main(){
	int T,r,w,s;scanf("%d",&T);
	while(T--){
		memset(c,0,sizeof c);
		s = 0;
		scanf("%d %d",&r,&w);
		for(int i = 1; i <= r; i++){ //从1开始防止搜索时搜到下标-1 
			for(int j = 1; j <= w; j++){
				scanf("%d",&c[i][j]);
				if(c[i][j]>0)
					s++;//俯视图上表面积 
			}
		}
		for(int i = 1; i <= r; i++){
			for(int j = 1; j <= w; j++){
				for(int k = 0; k < 4;k++){
					if(/*(i+dr[k][0]) <= r && (i+dr[k][0]) >= 0 &&(j+dr[k][1]) <= w && (j+dr[k][1]) >= 0 && */c[i][j] > c[i+dr[k][0]][j+dr[k][1]]){ //小于不行？？ 
						s += (-1)*(c[i+dr[k][0]][j+dr[k][1]]-c[i][j]); //搞反了 
					}
				}
			}
		}
		printf("%d\n",s);
	}
	return 0;
}