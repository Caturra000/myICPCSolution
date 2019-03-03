#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define FOR( i , a , b ) for ( int i = a ; i <= b ; ++ i )
#define RE freopen("1.in","r",stdin);
#define bug(x) cout<<#x<<":"<<(x)<<endl;

#define Mid ((l+r)>>1)      //括号！
#define lson rt<<1,l,Mid
#define rson rt<<1|1,Mid+1,r

const int maxn= 50005;
const int inf=0x3f3f3f3f;
int Max[maxn<<2],Min[maxn<<2];
int ans1,ans2;

void build(int rt,int l,int r)
{
    if(l==r){
        scanf("%d",&Max[rt]);
        Min[rt] = Max[rt];
    }else{
        build(lson);
        build(rson);
        Max[rt] = max( Max[rt<<1], Max[rt<<1|1]);
        Min[rt] = min( Min[rt<<1], Min[rt<<1|1]);
    }
}

void query(int rt,int l,int r,int L,int R)
{
    if(L <= l && r <= R){
        ans1 = max(ans1,Max[rt]);
        ans2 = min(ans2,Min[rt]);
    }else{
        if( L <= Mid)
            query(lson,L,R);
        if( R > Mid)
            query(rson,L,R);
    }
}

int main()
{
    int n,m,L,R;
    while(scanf("%d%d",&n,&m)!=EOF){
        build(1,1,n);
        while(m--){
            ans1 = -inf,ans2 = inf;
            scanf("%d%d",&L,&R);
            query(1,1,n,L,R);
            printf("%d\n", ans1-ans2);
        }
    }
    return 0;
}
//test