#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>
#define ll long long

using namespace std;

const int N=100000+7;

int root[N],tot;
int Ls[N*30],Rs[N*30],add[N*30];
ll sum[N*30];

int n,m;

inline int bulidtree(int L,int R){
    int k=tot++;
    add[k]=0;

    if (L==R){ 
        scanf("%lld",&sum[k]);
        return k;
    }

    int mid=(L+R)>>1;
    Ls[k]=bulidtree(L,mid);
    Rs[k]=bulidtree(mid+1,R);

    sum[k]=sum[Ls[k]]+sum[Rs[k]];

    return k;
}

inline int update(int o,int L,int R,int x,int LL,int RR){
    int k=tot++;
    Ls[k]=Ls[o]; Rs[k]=Rs[o]; add[k]=add[o]; sum[k]=sum[o];

    sum[k]+=(ll)x*(R-L+1);    

    if (LL==L && RR==R){
        add[k]+=x;
        return k;
    }

    int mid=(LL+RR)>>1;
    if (R<=mid) Ls[k]=update(Ls[k],L,R,x,LL,mid);
    else if (L>mid) Rs[k]=update(Rs[k],L,R,x,mid+1,RR);
    else {
        Ls[k]=update(Ls[k],L,mid,x,LL,mid);
        Rs[k]=update(Rs[k],mid+1,R,x,mid+1,RR);
    }

    return k;
}

inline ll query(int o,int L,int R,int LL,int RR){
    if (L==LL && R==RR) return sum[o];

    int mid=(LL+RR)>>1;

    ll ret=(ll)add[o]*(R-L+1);

    if (R<=mid) return ret+query(Ls[o],L,R,LL,mid);
    else if (L>mid) return ret+query(Rs[o],L,R,mid+1,RR);
    else return ret+query(Ls[o],L,mid,LL,mid)+query(Rs[o],mid+1,R,mid+1,RR);
}

int main(){
    int x,L,R;
    int now;
    char ch[3];

    bool f=false;

    while (~scanf("%d%d",&n,&m)){
        if (f) puts("");
        else f=true;

        tot=0;
        root[0]=bulidtree(1,n);
        now=0;

        while (m--){
            scanf("%s",ch);
            if (ch[0]=='C') {
                scanf("%d%d%d",&L,&R,&x);
                now++;
                root[now]=update(root[now-1],L,R,x,1,n);
            }
            else if (ch[0]=='Q') {
                scanf("%d%d",&L,&R);
                printf("%lld\n",query(root[now],L,R,1,n));
            }
            else if (ch[0]=='H'){
                scanf("%d%d%d",&L,&R,&x);
                printf("%lld\n",query(root[x],L,R,1,n));
            }
            else if (ch[0]=='B') {
                scanf("%d",&now);
            }
        }
    }

    return 0;
}
//test