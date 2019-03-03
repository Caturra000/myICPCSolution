#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e6+11;
int F[maxn],W[maxn],C[maxn],V,N;
void zeroOnePack(int F[],int C,int W){
    for(int v = V; v >= C; v--)
        F[v] = max(F[v],F[v-C]+W);
}
int main(){
    while(scanf("%d%d",&N,&V)!=EOF){
        for(int i = 1; i <= N; i++){
            scanf("%d%d",&C[i],&W[i]);
        }
        memset(F,0,sizeof F);
        for(int i = 1; i <= N; i++){
            zeroOnePack(F,C[i],W[i]);
        }
        printf("%d\n",F[V]);
    }
    return 0;
}