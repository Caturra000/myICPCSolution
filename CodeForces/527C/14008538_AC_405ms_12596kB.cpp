#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
using namespace std;
const int MAXN = 4e5+11;
const int INF = 0x7fffffff;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
set<ll> st[2];
multiset<ll> mst[2];
char str[666];
int main(){
    ll w,h,n;
    while(cin>>w>>h>>n){
        rep(i,0,1) st[i].clear(),mst[i].clear();
        st[0].insert(0);st[1].insert(0);
        st[0].insert(w);mst[0].insert(w);//x length
        st[1].insert(h);mst[1].insert(h);//y height
        rep(i,1,n){
            scanf("%s",str);
            ll res=0;
            if(str[0]=='H'){
                ll y=read();
                set<ll>::iterator it1,it2;
                multiset<ll>::iterator it3,it4;
                it1=it2=st[1].lower_bound(y);
                it1--;
                ll yy1=*it1,yy2=*it2;
                st[1].insert(y); mst[1].erase(mst[1].find(yy2-yy1)); 
                mst[1].insert(y-yy1); mst[1].insert(yy2-y);
                it3=mst[1].end();it4=mst[0].end();
                it3--;it4--;
                res=(*it3)*(*it4);
            }else{
                ll x=read();
                set<ll>::iterator it1,it2;
                multiset<ll>::iterator it3,it4;
                it1=it2=st[0].lower_bound(x);
                it1--;
                ll xx1=*it1,xx2=*it2;
                st[0].insert(x); mst[0].erase(mst[0].find(xx2-xx1)); 
                mst[0].insert(x-xx1); mst[0].insert(xx2-x);
                it3=mst[1].end();it4=mst[0].end();
                it3--;it4--;
                res=(*it3)*(*it4);
            }
            println(res);
        }
    }
    return 0;
}