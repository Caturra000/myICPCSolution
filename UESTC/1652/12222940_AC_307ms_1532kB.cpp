#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
double dp[2][30010];// n m
vector<int> vec[1003];
int n,m,p,k,a,b;
int main(){
    while(scanf("%d%d%d%d",&m,&k,&n,&p)!=EOF){
        memset(dp,0,sizeof dp);dp[0][p]=1;
        memset(vec,0,sizeof vec);
        rep(i,1,k){
            scanf("%d%d",&a,&b);
            vec[b].push_back(a);
        }
        rep(i,1,n) sort(vec[i].begin(),vec[i].end());
        vector<int>::iterator it;
        if(m>=2) rep(i,0,n-1){
            memset(dp[i+1&1],0,sizeof dp[i+1&1]);
            rep(j,1,m) if( ( it = find(vec[i+1].begin(),vec[i+1].end(),j) ) !=vec[i+1].end() ) dp[i+1&1][j]=-6666666;
            rep(j,1,m){
                if(dp[i&1][j]<=0) continue;
                if(j==1){
                    if(dp[i+1&1][j+1]>=0) dp[i+1&1][j+1]+=1.0/2.0*dp[i&1][j];
                    if(dp[i+1&1][j]>=0) dp[i+1&1][j]+=1.0/2.0*dp[i&1][j];
                }
                else if(j==m){
                    if(dp[i+1&1][j-1]>=0) dp[i+1&1][j-1]+=1.0/2.0*dp[i&1][j];
                    if(dp[i+1&1][j]>=0) dp[i+1&1][j]+=1.0/2.0*dp[i&1][j];
                }
                else{
                    if(dp[i+1&1][j]>=0) dp[i+1&1][j]+=1.0/3.0*dp[i&1][j];
                    if(dp[i+1&1][j-1]>=0) dp[i+1&1][j-1]+=1.0/3.0*dp[i&1][j];
                    if(dp[i+1&1][j+1]>=0) dp[i+1&1][j+1]+=1.0/3.0*dp[i&1][j];
                }
            }
        }
        else{
            bool flag=0;
            rep(i,1,n)  if((it=find(vec[i].begin(),vec[i].end(),1))!=vec[i].end()) flag=1;
            if(flag==1) printf("0.000000\n");
            else printf("1.000000\n");
            continue;
        }
        double ans=0;
        rep(j,1,m) if( ( it = find(vec[n].begin(),vec[n].end(),j) ) !=vec[n].end() ) dp[n&1][j]=-1;
        rep(i,1,m) ans+=(dp[n&1][i]<=0?0:dp[n&1][i]);
        printf("%.6lf\n",ans);
    }
    return 0;
}