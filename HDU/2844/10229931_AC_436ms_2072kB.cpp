#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+7;
int F[maxn],C[maxn],W[maxn],M[maxn],V,n,ans; 
void zeroOnePack(int F[],int C,int W){
	for(int v = V; v >= C; v--)
		F[v] = max(F[v],F[v-C]+W);
}
void completePack(int F[],int C,int W){
	for(int v = C; v <= V; v++)
		F[v] = max(F[v],F[v-C]+W);
}
void multiPack(int F[],int C,int W,int M){
	if(M*C>=V){
		completePack(F,C,W);
		return ;
	}
	int k = 1;
	while(k<M){
		zeroOnePack(F,k*C,k*W);
		M=M-k;
		k<<=1;
	}
	zeroOnePack(F,M*C,M*W);
}
int main(){
	while(scanf("%d%d",&n,&V),n){
		ans=0;memset(F,0x80,sizeof F);F[0]=0;
		for(int i = 1; i <= n; i++)
			scanf("%d",&C[i]);
		for(int i = 1; i <= n; i++)
			scanf("%d",&M[i]);
		for(int i = 1; i <= n; i++)
			multiPack(F,C[i],C[i],M[i]);
		for(int i = 1; i <= V; i++)
			if(F[i]>0) ans++;
		printf("%d\n",ans);
	}
	return 0;
}