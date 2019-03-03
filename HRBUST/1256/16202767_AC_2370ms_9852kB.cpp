#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
vector<int >mp[25];
int w[50][50];
int a[50];
int dp[(1<<20)];
int vis[(1<<20)];
int chose[1000];
int val[1000];
int n,k,cnt;
void init()
{
    memset(chose,0,sizeof(chose));
    cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(i==j||j==k||i==k)continue;
                chose[cnt]+=(1<<i);
                chose[cnt]+=(1<<j);
                chose[cnt]+=(1<<k);
                val[cnt]=a[i]+a[j]+a[k]+w[i][j]+w[i][k]+w[j][k];
                cnt++;
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&k,&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&w[i][j]);
            }
        }
        init();
        int end=(1<<n);
        queue<int >s;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<cnt;i++)s.push(chose[i]),dp[chose[i]]=val[i];
        for(int i=0;i<k-1;i++)
        {
            memset(vis,0,sizeof(vis));
            while(!s.empty())
            {
                int u=s.front();
                s.pop();
                for(int j=0;j<cnt;j++)
                {
                    if((u&chose[j])==0)
                    {
                        int v=u+chose[j];
                        dp[v]=max(dp[v],dp[u]+val[j]);
                        if(vis[v]==0)
                        {
                            vis[v]=1;
                        }
                    }
                }
            }
            for(int j=0;j<end;j++)
            {
                if(vis[j]==1)
                {
                    s.push(j);
                }
            }
        }
        int output=0;
        for(int i=0;i<end;i++)
        {
            int num=0;
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j))==0)continue;
                else num++;
            }
            if(num==k*3)
            output=max(output,dp[i]);
        }
        printf("%d\n",output);
    }
}//atest