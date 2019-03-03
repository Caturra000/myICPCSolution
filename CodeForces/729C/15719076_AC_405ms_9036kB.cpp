#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
const int MAXN = 2e5 + 11;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
typedef long long ll;
ll read(){
    ll x=0, f=1; register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct QAQ{
    int c,v;
    QAQ(){}
    QAQ(int _c,int _v){
        c=_c;
        v=_v;
    }
    bool operator < (const QAQ &rhs)const{
        return v<rhs.v;
    }
}a[MAXN];
int b[MAXN],n,k,s,T;
bool C(int x){
    int t=0;
    rep(i,1,k){
        int d=b[i]-b[i-1];
        if(a[x].v<d) return 0;
        if(a[x].v>=2*d) t+=d;
        else t+=3*d-a[x].v;
        if(t>T) return 0;
    }
    int d=s-b[k];
    if(a[x].v<d) return 0;
    if(a[x].v>=2*d) t+=d;
    else t+=3*d-a[x].v;
    if(t>T) return 0;
    return 1;
}
int main(){
    while(cin>>n>>k>>s>>T){
        rep(i,1,n){
            int c=read();
            int v=read();
            a[i]=QAQ(c,v);
        }
        rep(i,1,k) b[i]=read();
        sort(a+1,a+1+n);
        sort(b+1,b+1+k);
        int lo=1,hi=n,ans;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(C(mid)) hi=mid;
            else lo=mid+1;
        }
        if(C(lo)) ans=lo;
        else ans=-1;
        if(~ans){
            set<int> s;
            rep(i,ans,n) s.insert(a[i].c);
            println(*s.begin());
        }else println(-1);
    }
    return 0;
}