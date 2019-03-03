#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#include<unordered_map>
#define rep(i,j,k) for( int i=j;i<=k;i++)
#define rrep(i,j,k) for( int i=j;i>=k;i--)
#define erep(i,u) for( int i=head[u];~i;i=nxt[i])
#define fastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);ssb=cin.rdbuf()
#define println(x) print(x),print('\n')
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using P  = pair<ll,ll>;
const int MAXN = 5e5+11;
const int INF  = 0x3f3f3f3f;
const double EPS = 1e-7;
const int BUFL = 1e6+11;
char Obuf[BUFL],Ibuf[BUFL];
char *optr=Obuf,*ist=0,*ied=0;
streambuf *sb,*ssb;
inline void print(char c){optr==Obuf+BUFL?(sb->sputn(Obuf,BUFL),optr=Obuf),*optr++=c:*optr++=c;}
inline void flush(){sb->sputn(Obuf,optr-Obuf);}
inline char pick(){return ist==ied?ied=Ibuf+ssb->sgetn(ist=Ibuf,BUFL),(ist==ied?-1:*ist++):*ist++;}
template<class T>
inline void print(T x){
    if(x==0) {print(char(48));return;}
    if(x<0){print(char('-'));x=-x;}
    static char buf[233];
    register int cnt;
    for(cnt=0;x;x/=10) buf[++cnt]=x%10|48;
    while(cnt) print(buf[cnt--]);
}
template<class T>
inline int read(T &o){
    ll x; register char c,f; f=1;
    while(!((c=pick())>='0'&&c<='9')&&(c^-1)&&(c^45));
    if(c==-1) return EOF;
    if(c==45) c=pick(),f=0;
    for(x=c-48;(c=pick())>='0'&&c<='9';(x=((x<<3)+(x<<1)))+=c-48);
    o=f?x:-x;return 1;
}

ll a[MAXN],n,m,op;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("stdin.txt","r",stdin);
    #endif
    while(~scanf("%lld",&m)){
        n=0; 
        ll ans=0;
        int l=1,r=0;
        while(m--){
            scanf("%lld",&op);
            if(op==1){
                scanf("%lld",&a[++n]);
            }else{
                while(r<n&&a[r+1]*(r+1)<ans+a[n]) ans+=a[++r];
//                cout<<fixed<<setprecision(12)<<1.0*a[n]-1.0*(ans+a[n])/(r+1)<<endl;
                printf("%.12lf\n",1.0*a[n]-1.0*(ans+a[n])/(r+1));
            }
        }
    }
    return 0;
}