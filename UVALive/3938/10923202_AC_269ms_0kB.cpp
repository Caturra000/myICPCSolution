#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+11;
typedef long long ll;
typedef pair<int,int> P;
ll pre[maxn];
ll sum(int l,int r){//O(1)
    return pre[r]-pre[l-1];
}
ll sum(P p){
    return sum(p.first,p.second);
}
P better(P a,P b){//NOTE:字典序处理
    if(sum(a)!=sum(b)) return sum(a)>sum(b)?a:b;
    return a<b?a:b;//按字典序排序
}
// int qL,qR;
struct ST{
    int mp[maxn<<2],ms[maxn<<2];
    P mx[maxn<<2];
    int lc[maxn<<2],rc[maxn<<2],lx[maxn<<2],rx[maxn<<2];
    int root,tot;
    void init(){
        memset(mp,0,sizeof mp);memset(ms,0,sizeof ms);
        memset(mx,0,sizeof mx);
        root=tot=0;
        lc[tot]=rc[tot]=0;
    }
    int node(){
        lc[tot]=rc[tot]=lx[tot]=rx[tot]=mp[tot]=ms[tot]=mx[tot].first=mx[tot].second=0;
        return tot++;
    }
    void pu(int now){
        ll v1=sum(lx[now],mp[lc[now]]);
        ll v2=sum(lx[now],mp[rc[now]]);
        //NOTE:前缀和必然与lx[now]相关联
        if(v1==v2) mp[now]=min(mp[lc[now]],mp[rc[now]]);//NOTE:字典序
        else mp[now]=v1>v2?mp[lc[now]]:mp[rc[now]];

        v1=sum(ms[lc[now]],rx[now]);
        v2=sum(ms[rc[now]],rx[now]);
        if(v1==v2) ms[now]=min(ms[lc[now]],ms[rc[now]]);
        else ms[now]=v1>v2?ms[lc[now]]:ms[rc[now]];

        mx[now]=better(mx[lc[now]],mx[rc[now]]);
        mx[now]=better(mx[now],P(ms[lc[now]],mp[rc[now]]));//中间
        //NOTE:左边的后缀和加右边的前缀和
    }
    int build(int l,int r){
        int now=node();
        lx[now]=l;rx[now]=r;
        if(l==r){
            mp[now]=ms[now]=l;
            mx[now]=P(l,l);
            return now;
        }
        int m=l+r>>1;
        lc[now]=build(l,m);
        rc[now]=build(m+1,r);
        pu(now);
        return now;
    }
    P query_p(int now,int L,int R){
        if(mp[now]<=R) return P(lx[now],mp[now]);
        int m=lx[now]+rx[now]>>1;
        if(R<=m) return query_p(lc[now],L,R);
        P i = query_p(rc[now],L,R);//???
        i.first=lx[now];
        return better(i,P(lx[now],mp[lc[now]]));
    }
    P query_s(int now,int L,int R){
        if(L<=ms[now]) return P(ms[now],rx[now]);
        int m=lx[now]+rx[now]>>1;
        if(L>m) return query_s(rc[now],L,R);
        P i = query_s(lc[now],L,R);
        i.second=rx[now];
        return better(i,P(ms[rc[now]],rx[now]));
    }
    P query(int now,int L,int R){
        if(L<=lx[now]&&rx[now]<=R) return mx[now];
        int m=lx[now]+rx[now]>>1;
        if(R<=m) return query(lc[now],L,R);//完全在左子树
        if(L>m) return query(rc[now],L,R);//完全在右子树
        P i1=query_p(rc[now],L,R);
        P i2=query_s(lc[now],L,R);
        P i3=better(query(lc[now],L,R),query(rc[now],L,R));
        return better(P(i2.first,i1.second),i3);//L<=m||R>m
    }
}st;
int main(){
    int kase=0,n,m,a,b;
    while(scanf("%d%d",&n,&m)!=EOF){
        pre[0]=0;st.init();
        for(int i = 1; i <= n; i++){
            scanf("%d",&a);
            pre[i]=pre[i-1]+a;
        }
        st.build(1,n);
        printf("Case %d:\n",++kase);
        while(m--){
            scanf("%d%d",&a,&b);
            // ql=l,qR=r;
            P ans=st.query(st.root,a,b);
            printf("%d %d\n",ans.first,ans.second);
        }
    }
    return 0;
}