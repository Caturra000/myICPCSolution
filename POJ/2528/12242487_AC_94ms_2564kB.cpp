#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn  = 100000;
bool ha[maxn];
int col[maxn*4];
struct node
{
    int l,r;
}q[maxn];
int ans;
int x[maxn*2];
void pushdown(int rt)
{
    if(col[rt] != -1)
    {
        col[rt*2] = col[rt *2+1] = col[rt];
        col[rt] = -1;
    }
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l && r<=R)
    {
        col[rt] = c;
        return;
    }
    pushdown(rt);
    int mid = (r+l)>>1;
    if(L<=mid)
        update(L,R,c,l,mid,rt*2);
    if(R > mid)
        update(L,R,c,mid+1,r,rt*2+1);
}
void query(int l,int r,int rt)
{
    if(col[rt]!=-1)
    {
        if(!ha[col[rt]])
            ans++;
        ha[col[rt]] = true;
        return;
    }
    if(l == r)
        return ;
    int mid = (r+l)>>1;
    query(l,mid,rt*2);
    query(mid+1,r,rt*2+1);
}
int main()
{
    int n,t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        int cnt = 0;
        scanf("%d",&n);
        for(i = 0; i < n; i++)
        {
            scanf("%d%d",&q[i].l,&q[i].r);
            x[cnt++] = q[i].l;
            x[cnt++] = q[i].r;
        }
        sort(x,x+cnt);
        int m = 1;
        for(i = 1; i < cnt; i++)
            if(x[i] != x[i-1])
                x[m++] = x[i];
        for(i = m-1; i > 0; i--)
            if(x[i] != x[i-1]+1)
                x[m++] = x[i-1]+1;
        sort(x,x+m);
        memset(col,-1,sizeof(col));
        for(i = 0; i < n; i++)
        {
            int l = lower_bound(x,x+m,q[i].l)-x;
            int r = lower_bound(x,x+m,q[i].r)-x;
            update(l,r,i,0,m,1);
        }
        memset(ha,0,sizeof(ha));
        ans = 0;
        query(0,m,1);
        printf("%d\n",ans);
    }
    return 0;
}//test