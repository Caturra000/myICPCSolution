#include <cstdio>
#include <cstring>
#include <ctime>
#include <queue>
#include <cstdlib>
#define N 500010
#define inf 0x3f3f3f3f
using namespace std;
int ch[N][2],f[N],siz[N],val[N],tmx[N],lmx[N],rmx[N],rev[N],sum[N],cov[N],tar[N];
unsigned int SEED = 233;
int Rand(){
    SEED=SEED*233333+66666;
    return SEED;
}
int inline read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int max(int x,int y){if (x>y) return x;return y;}
int min(int x,int y){if (x<y) return x;return y;}
void swap(int &a,int &b){a^=b,b^=a,a^=b;}
queue<int>trashcan;
int root,cnt;
int new_node(int v)
{
    int x;
    if (!trashcan.empty())
        x=trashcan.front(),trashcan.pop();
    else
        x=++cnt;
    ch[x][0]=ch[x][1]=f[x]=rev[x]=0;
    cov[x]=inf,tar[x]=Rand(),siz[x]=1;
    val[x]=sum[x]=tmx[x]=v;
    lmx[x]=rmx[x]=max(v,0);
    return x;
}
void update(int x)
{
    if (ch[x][0] && ch[x][1])
    {
        siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;
        sum[x]=sum[ch[x][0]]+sum[ch[x][1]]+val[x];
        tmx[x]=max(tmx[ch[x][0]],tmx[ch[x][1]]);
        tmx[x]=max(tmx[x],rmx[ch[x][0]]+val[x]+lmx[ch[x][1]]);
        lmx[x]=max(lmx[ch[x][0]],sum[ch[x][0]]+val[x]+lmx[ch[x][1]]);
        rmx[x]=max(rmx[ch[x][1]],sum[ch[x][1]]+val[x]+rmx[ch[x][0]]);
    }
    else
    if (ch[x][0])
    {
        siz[x]=siz[ch[x][0]]+1;
        sum[x]=sum[ch[x][0]]+val[x];
        tmx[x]=max(tmx[ch[x][0]],rmx[ch[x][0]]+val[x]);
        lmx[x]=max(lmx[ch[x][0]],sum[ch[x][0]]+val[x]);
        lmx[x]=max(0,lmx[x]);
        rmx[x]=max(0,val[x]+rmx[ch[x][0]]);
    }
    else
    if (ch[x][1])
    {
        siz[x]=siz[ch[x][1]]+1;
        sum[x]=sum[ch[x][1]]+val[x];
        tmx[x]=max(tmx[ch[x][1]],lmx[ch[x][1]]+val[x]);
        rmx[x]=max(rmx[ch[x][1]],sum[ch[x][1]]+val[x]);
        rmx[x]=max(0,rmx[x]);
        lmx[x]=max(0,lmx[ch[x][1]]+val[x]);
    }
    else
    {
        siz[x]=1,sum[x]=tmx[x]=val[x];
        lmx[x]=rmx[x]=max(val[x],0);
    }
}
void reverse(int x)
{
    swap(ch[x][0],ch[x][1]);
    swap(lmx[x],rmx[x]);
    rev[x]^=1;
}
void cover(int x,int v)
{
    val[x]=v,sum[x]=siz[x]*v;
    lmx[x]=rmx[x]=max(sum[x],0);
    tmx[x]=max(sum[x],val[x]);
    cov[x]=v;
}
void pushdown(int x)
{
    if (rev[x])
    {
        if (ch[x][0]) reverse(ch[x][0]);
        if (ch[x][1]) reverse(ch[x][1]);
    }
    if (cov[x]!=inf)
    {
        if (ch[x][0]) cover(ch[x][0],cov[x]);
        if (ch[x][1]) cover(ch[x][1],cov[x]);
    }
    rev[x]=0;cov[x]=inf;
}
int build(int *data,int n)
{
    int x,last=0;static int sta[N],top;
    for(int i=1;i<=n;i++)
    {
        x=new_node(data[i]),last=0;
        while(top && tar[sta[top]]>tar[x])
            update(sta[top]),last=sta[top],
            sta[top--]=0;
        if (top)
            ch[sta[top]][1]=x;
        ch[x][0]=last,sta[++top]=x;
    }
    while(top)
        update(sta[top--]);
    return sta[1];
}
void split(int now,int k,int &x,int &y)
{
    if (!now) x=y=0;
    else
    {
        pushdown(now);
        if (siz[ch[now][0]]>=k)
            y=now,split(ch[now][0],k,x,ch[now][0]);
        else
            x=now,split(ch[now][1],k-siz[ch[now][0]]-1,ch[now][1],y);
        update(now);
    }
}
int merge(int x,int y)
{
    if (x) pushdown(x);
    if (y) pushdown(y);
    if (x*y==0) return x+y;
    if (tar[x]<tar[y])
    {
        ch[x][1]=merge(ch[x][1],y);
        update(x);return x;
    }
    else
    {
        ch[y][0]=merge(x,ch[y][0]);
        update(y);return y;
    }
}
void trash(int x)
{
    if (!x) return;
    trashcan.push(x);
    trash(ch[x][0]);
    trash(ch[x][1]);
}
void insert()
{
    int pos=read(),len=read(),x,y;
    static int datas[N];
    for (int i=1;i<=len;i++)
        datas[i]=read();
    int rt=build(datas,len);
    split(root,pos,x,y);
    root=merge(merge(x,rt),y);
}
void delet()
{
    int pos=read(),len=read(),x1,x2,y1,y2;
    split(root,pos-1,x1,x2);
    split(x2,len,y1,y2);
    root=merge(x1,y2);
    trash(y1);
}
void covers()
{
    int pos=read(),len=read(),v=read(),x1,x2,y1,y2;
    split(root,pos-1,x1,x2);
    split(x2,len,y1,y2);
    cover(y1,v);
    root=merge(x1,merge(y1,y2));
}
void reverses()
{
    int pos=read(),len=read(),x1,x2,y1,y2;
    split(root,pos-1,x1,x2);
    split(x2,len,y1,y2);
    reverse(y1);
    root=merge(x1,merge(y1,y2));
}
void sums()
{
    int pos=read(),len=read(),x1,x2,y1,y2;
    split(root,pos-1,x1,x2);
    split(x2,len,y1,y2);
    printf("%d\n",sum[y1]);
    root=merge(x1,merge(y1,y2));
}
void maxs()
{
    printf("%d\n",tmx[root]);
}
int main() 
{ 
    static int n=read(),m=read(),a[N]; 
    for (int i=1;i<=n;i++) 
        a[i]=read();
    root=build(a,n); 
    static char s[20]; 
    while (m--) 
    {
        scanf("%s",s); 
        if (s[0]=='I') insert();  
        else if (s[0]=='D') delet(); 
        else if (s[0]=='M' && s[2] =='K') covers();
        else if (s[0]=='R') reverses();
        else if (s[0]=='G') sums();
        else maxs(); 
    }     
}
//test 2