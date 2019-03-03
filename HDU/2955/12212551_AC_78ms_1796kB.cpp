#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define scan(a) scanf("%d",&a)
#define scand(a) scanf("%lf",&a)
int C[maxn],n,V;
double W[maxn],F[2][maxn],P;
int main(){
    int T; scan(T);
    while(T--){
        scand(P);scan(n);
        rep(i,1,n){
            scan(C[i]);
            scand(W[i]);
        }
        int sum=0;
        rep(i,1,n) sum+=C[i];//cout<<sum<<endl;
        rep(i,1,sum) F[0][i]=0,F[1][i]=0;//zuidabubeizhua
        F[0][0]=F[1][0]=1.0;
        rep(i,1,n){
            rep(j,0,sum){
                if(j>=C[i])F[i&1][j]=max(F[i-1&1][j],F[i-1&1][j-C[i]]*(1.0-W[i]));
                else F[i&1][j]=F[i-1&1][j];
            }
        }
        int ans=-1;
        rep(i,0,sum) if(1-F[n&1][i]<=P) ans=i;
        printf("%d\n",ans);
    }
    return 0;
}