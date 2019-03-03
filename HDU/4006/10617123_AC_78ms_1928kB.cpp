#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int heap[1000010],siz;
void down(int rt)
{
    while(rt<siz)
    {
        int son=rt*2;
        if(son+1<=siz) son=heap[son]>heap[son+1]?son+1:son;
        if(son<=siz && heap[rt]>heap[son]) swap(heap[rt],heap[son]);
            else return;
        rt=son;
    }
}
void up(int rt)
{
    while(rt!=1)
    {
        if(heap[rt]<heap[rt/2]) swap(heap[rt],heap[rt/2]);
        else break;
        rt>>=1;
    }
}
void heap_push(int k)
{
    heap[++siz]=k;
    up(siz);
}
void heap_pop()
{
    heap[1]=heap[siz--];
    down(1);
}
int main()
{
    int n,k,x;
    char c[2];
    while(scanf("%d%d",&n,&k)!=-1)
    {
        siz=0;
        while(n--)
        {
            scanf("%s",&c);
            if(c[0]=='I')
            {
                scanf("%d",&x);
                heap_push(x);
                if(siz>k) heap_pop();
            }
            else printf("%d\n",heap[1]);
        }
    }
}
//just for test