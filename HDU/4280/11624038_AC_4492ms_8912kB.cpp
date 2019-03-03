#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int head[210000], s, t, nv, maxint=0x3f3f3f3f, cnt;
int cur[210000], pre[210000], q[5000000], d[210000], num[210000];
struct node
{
    int u, v, cap, next;
}edge[11000000];
void add(int u, int v, int cap)
{
    edge[cnt].v=v;
    edge[cnt].cap=cap;
    edge[cnt].next=head[u];
    head[u]=cnt++;

    edge[cnt].v=u;
    edge[cnt].cap=cap;
    edge[cnt].next=head[v];
    head[v]=cnt++;
}
void bfs()
{
    memset(num,0,sizeof(num));
    memset(d,-1,sizeof(d));
    int f1=0, f2=0, i;
    q[f1++]=t;
    d[t]=0;
    num[0]=1;
    while(f1>=f2)
    {
        int u=q[f2++];
        for(i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].v;
            if(d[v]==-1)
            {
                d[v]=d[u]+1;
                num[d[v]]++;
                q[f1++]=v;
            }
        }
    }
}
void isap()
{
    memcpy(cur,head,sizeof(cur));
    int flow=0, u=pre[s]=s, i;
    bfs();
    while(d[s]<nv)
    {
        if(u==t)
        {
            int f=maxint, pos;
            for(i=s;i!=t;i=edge[cur[i]].v)
            {
                if(f>edge[cur[i]].cap)
                {
                    f=edge[cur[i]].cap;
                    pos=i;
                }
            }
            for(i=s;i!=t;i=edge[cur[i]].v)
            {
                edge[cur[i]].cap-=f;
                edge[cur[i]^1].cap+=f;
            }
            flow+=f;
            //printf("--");
            u=pos;
        }
        for(i=cur[u];i!=-1;i=edge[i].next)
        {
            if(d[edge[i].v]+1==d[u]&&edge[i].cap)
            {
                break;
            }
        }
        if(i!=-1)
        {
            cur[u]=i;
            pre[edge[i].v]=u;
            u=edge[i].v;
        }
        else
        {
            if(--num[d[u]]==0) break;
            int mind=nv+1;
            for(i=head[u];i!=-1;i=edge[i].next)
            {
                if(mind>d[edge[i].v]&&edge[i].cap)
                {
                    mind=d[edge[i].v];
                    cur[u]=i;
                }
            }
            d[u]=mind+1;
            num[d[u]]++;
            u=pre[u];
        }
    }
    printf("%d\n",flow);
}
int read(){
    int flag = 0, x = 0;
    char ch = ' ';
    while(ch != '-' && (ch > '9' || ch < '0')) ch = getchar();
    if(ch == '-') flag = 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    return flag ? -x : x;
}
int main()
{
    int T, n, m, i, j, a, b, c, x, y, min1, max1;
    scanf("%d",&T);
    while(T--)
    {
        memset(head,-1,sizeof(head));
        cnt=0;
        n=read();m=read();
        min1=999999;
        max1=-999999;
        for(i=1;i<=n;i++)
        {
            x=read();y=read();
            if(min1>x)
            {
                min1=x;
                s=i;
            }
           if(max1<x)
           {
               max1=x;
               t=i;
           }
        }
        while(m--)
        {
            a=read();
            b=read();
            c=read();
            add(a,b,c);
        }
        nv=n+1;
        isap();
    }
    return 0;
}
//test