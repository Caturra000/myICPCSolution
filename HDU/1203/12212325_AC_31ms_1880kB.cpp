#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define scan(a) scanf("%d",&a)
#define scand(a) scanf("%lf",&a)
int C[maxn],n,V;
double W[maxn],F[2][maxn];
int main(){
    while(scan(V)!=EOF){
        scan(n);
        if(V==0&&n==0)break;
        rep(i,1,n){
            scan(C[i]);
            scand(W[i]);
        }
        rep(i,0,V) F[0][i]=1,F[1][i]=1;
        rep(i,1,n){
            rep(j,0,V){
                if(C[i]>j) F[i&1][j]=F[i-1&1][j];
                else F[i&1][j]=min(F[i-1&1][j],F[i-1&1][j-C[i]]*(1.0-W[i]));
            }
        }
        double ans=1.0;
        rep(i,0,V) ans=min(ans,F[n&1][i]);
        printf("%.1f%%\n",(1.0-ans)*100);
    }
    return 0;
}