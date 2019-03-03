#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define scan(a) scanf("%d",&a)
#define rep(i,j,k) for(int i = j; i <= k; i++)
using namespace std;
const int maxn = 1666;

bool F[maxn][maxn];
int len[maxn],n;
double query(double a,double b,double c){
    double p=(a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
bool dp[2][maxn][maxn];//使用前n的物品使得容量为v1和容量为v2的背包恰好装满
int C[maxn],W[maxn],V1,V2;
bool bag(int a,int b){
    V1=a,V2=b;
    rep(i,1,n){
        dp[i&1][0][0]=1;
        rep(j,0,V1){
            rep(k,0,V2){
                dp[i&1][j][k]|=dp[i-1&1][j][k];//not be used
                if(len[i]<=j) dp[i&1][j][k]|=dp[i-1&1][j-len[i]][k];
                if(len[i]<=k) dp[i&1][j][k]|=dp[i-1&1][j][k-len[i]];
            }
        }
    }
    return dp[n&1][V1][V2];
}

#define check(i,j) dp[n&1][i][j]
int main(){
    while(scan(n)!=EOF){
        int sum = 0;
        rep(i,1,n) scan(len[i]);
        rep(i,1,n) sum+=len[i];
        memset(F,0,sizeof F);
        double t=(double)sum/2;
        int tt=sum/2+1;
        int maxi=0,maxj=0;
        rep(i,1,tt){
            rep(j,1,tt){
                if(i+j>t){
                    F[i][j]=1;
                    maxi=i,maxj=j;
                }
                    
            }
        }
        double ans=0;
        bag(maxi,maxj); 
        rep(i,1,tt){
            rep(j,1,tt){
                int k = sum-i-j;
                if(F[i][j]&&k>=1&&i+j>k&&i+k>j&&j+k>i&&check(i,j)){
                    ans = max(ans,query(i,j,k));
                }
            }
        }
        long long aans= ans*100;
        printf("%lld\n",aans>0?aans:-1);
    }
    return 0;
}