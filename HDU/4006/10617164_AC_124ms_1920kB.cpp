#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
//const int maxn = 1e6+11;
int heap[1000010],sz;
void down(int rt){
    int lc,rc;
    while(rt<sz){
        lc=rt<<1,rc=rt<<1|1;
        if(rc<=sz) lc=heap[lc]>heap[rc]?rc:lc;
        if(lc<=sz&&heap[rt]>heap[lc]){
            heap[rt]^=heap[lc];
            heap[lc]^=heap[rt];
            heap[rt]^=heap[lc];
        }
        else return;
        rt=lc;
    }
}
void up(int rt){
    while(rt!=1){
        if(heap[rt]<heap[rt/2]){
            heap[rt]^=heap[rt/2];
            heap[rt/2]^=heap[rt];
            heap[rt]^=heap[rt/2];
        }
        else break;
        rt>>=1;
    }
}
void push(int k){
    heap[++sz]=k;
    up(sz);
}
void pop(){
    heap[1]=heap[sz--];
    down(1);
}
int main(){
    int n,k,x;char c[100];
    while(scanf("%d%d",&n,&k)!=EOF){
        sz=0;
        for(int i = 0; i < n; i++){
            scanf("%s",c);
            if(c[0]=='I'){
                scanf("%d",&x);
                push(x);
                if(sz>k) pop();
            }
            else printf("%d\n",heap[1]);
        }
    }
    return 0;
}