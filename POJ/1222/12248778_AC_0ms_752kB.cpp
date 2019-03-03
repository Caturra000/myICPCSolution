#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int maxn = 1e2+11;
const int dx[]={-1,0,0,0,1};
const int dy[]={0,-1,0,1,0};
int G[maxn][maxn],best[maxn][maxn],tmp[maxn][maxn];
int r,c;
int check(int x,int y){
	int t=G[x][y];
	rep(i,0,4){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx>=1&&tx<=r&&ty>=1&&ty<=c){
			t+=tmp[tx][ty];
		}
	}
	return t%2;
}
int cal(){
	rep(i,2,r) rep(j,1,c){
		if(check(i-1,j)==1){
			tmp[i][j]=1;
		}
	}
	rep(i,1,c) if(check(r,i)==1) return -1;
	int cnt=0;
	rep(i,1,r) rep(j,1,c) cnt+=tmp[i][j];
	return cnt;
}
void print(){
	rep(i,1,r){
		rep(j,1,c){
			if(j==c) printf("%d\n",best[i][j]);
			else printf("%d ",best[i][j]);
		}
	}
} 
int main(){
	r=5,c=6;
	int T,kase=0; scanf("%d",&T);
	while(T--){
		rep(i,1,r) rep(j,1,c) scanf("%d",&G[i][j]);
		int ans=-1;
		rep(i,0,(1<<c)-1){
			memset(tmp,0,sizeof tmp);
			rep(j,1,c) tmp[1][j]=i>>(j-1)&1;//最低位判断
			int cnt=cal();
			if(cnt>=0&&(cnt<ans||ans<0)){
				memcpy(best,tmp,sizeof tmp);
				ans=cnt;
			}
			
		}
		printf("PUZZLE #%d\n",++kase);
		if(~ans) print();
		else printf("IMPOSSIBLE\n"); 
	}
	return 0;
}