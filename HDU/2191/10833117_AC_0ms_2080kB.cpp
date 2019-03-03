#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+7;
int F[maxn],C[maxn],W[maxn],M[maxn],V,n,m,ans; 
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
	int T; scanf("%d",&T);
	while(T--){
		memset(F,0,sizeof F);
		scanf("%d%d",&n,&m);V=n;
		for(int i = 0; i < m; i++){
			scanf("%d%d%d",&C[i],&W[i],&M[i]);
		}
		for(int i = 0; i < m; i++){
			multiPack(F,C[i],W[i],M[i]);
		}
		printf("%d\n",F[V]);
	}
	return 0;
}