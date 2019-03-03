#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<iterator>
using namespace std;
const int maxn = 1211;
const int oo = 0x3f3f3f3f;
typedef pair<int,int> P;
vector<P> vec[maxn];
vector<int> F;
int dp[123][maxn];//mincost when  lowf of [1..i] = j 
int n,m,x,y;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(vec,0,sizeof vec);
        for(int i = 1; i <= n; i++){
            scanf("%d",&m);
            for(int j = 1; j <= m; j++){
                scanf("%d%d",&x,&y);
                vec[i].push_back(P(x,y));
            }
        }
        memset(dp,oo,sizeof dp);
        for(int i = 0; i < vec[1].size(); i++){
            P t = vec[1][i];
            dp[1][t.first]=min(dp[1][t.first],t.second);
        }
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < vec[i].size(); j++){
                P t=vec[i][j];
                for(int k = 0; k < maxn; k++){
                    if(dp[i-1][k]!=oo){
                        if(k<=t.first)
                            dp[i][k]=min(dp[i][k],dp[i-1][k]+t.second);
                        else
                            dp[i][t.first]=min(dp[i][t.first],dp[i-1][k]+t.second);
                    }   
                }
            }
        }
        double ans=-1;
        for(int i = 0; i < maxn; i++) if(dp[n][i]!=oo) ans=max(ans,(double)i/dp[n][i]);
        printf("%.3lf\n",ans);
    }
    return 0;
}