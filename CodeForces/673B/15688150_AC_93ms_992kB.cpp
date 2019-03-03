#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
const int MAXN = 1e5 + 11;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
typedef long long ll;
ll read(){
    ll x=0, f=1; register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
struct QAQ{
    int l,r;
    QAQ(){}
    QAQ(int ll,int rr){
        if(ll<rr) swap(ll,rr);
        l=ll,r=rr;
    }
    bool operator < (const QAQ&orz)const{
        if(l!=orz.l) return l>orz.l;
        return r>orz.r;
    }
}a[MAXN];
bool have[MAXN][2];
int main(){
    while(cin>>n>>m){
        memset(have,0,sizeof have);
        rep(i,1,m) a[i]=QAQ(read(),read());
        sort(a+1,a+1+m);
        int div1=n,div2=1;
        bool flag=0;
        rep(i,1,m){
            if(a[i].l<=div2) flag=1;
            if(a[i].r>=div1) flag=1;
            if(have[a[i].l][1]||have[a[i].r][0]) flag=1;
            if(flag) break;
            have[a[i].l][0]=have[a[i].r][1]=1;
            div1=min(div1,a[i].l);
            div2=max(div2,a[i].r);
        }
        if(flag) println(0);
        else println(div1-div2);
    }
    return 0;
}