#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+11;
int G[3][maxn],n;
int main(){
    while(scanf("%d",&n)^-1){
        memset(G,0,sizeof G);
        for(int i = 0; i <= n; i++) G[1&1][i]=1;
        for(int i = 1; i <= n-1; i++){
            for(int j = 0; j <= n; j++){
                for(int k = 0; k <= n; k+=i+1){
                    G[i+1&1][j+k]+=G[i&1][j];
                    
                }
                G[i&1][j]=0;
            }
        }
        printf("%d\n",G[n&1][n]);
    }
    return 0;
}