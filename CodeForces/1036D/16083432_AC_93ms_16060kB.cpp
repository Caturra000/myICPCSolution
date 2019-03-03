/*
#pragma GCC diagnostic error "-std=c++11"
#include<ext/pb_ds/priority_queue.hpp>
#include<bits/stdc++.h>
#define unordered_map map
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
const int MAXN = 1e5+11;
const int INF  = 0x3f3f3f3f; 

const int BUFL = 1e6+11;
char Obuf[BUFL],Ibuf[BUFL];
char *optr=Obuf,*ist=0,*ied=0;
streambuf *sb,*ssb;
#define println(x) print(x),print('\n');
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
inline int read(T &t){
    ll x; register char c,f; f=1;
    while(!isdigit(c=pick())&&(c^-1)&&(c^45));
    if(c==-1) return EOF;
    if(c==45) c=pick(),f=0;
    for(x=c-48;isdigit(c=pick());(x=((x<<3)+(x<<1)))+=c-48);
    t=f?x:-x;return 1;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("stdin.txt","r",stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sb=cout.rdbuf();
    ssb=cin.rdbuf();
    ll a,b;
    while(~read(a)){
        read(b);
        println(a+b);
    }
    flush();
    return 0;
}




*/
#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
typedef long long ll;
using namespace std;
const int MAXN = 3e5+11;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll ooo= 0x3f3f3f3f;
const int MOD = 1000000007;
const int BUFL = 1e6+11;
char Obuf[BUFL],Ibuf[BUFL];
char *optr=Obuf,*ist=0,*ied=0;
streambuf *sb,*ssb;
#define println(x) print(x),print('\n');
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
inline int read(T &t){
    ll x; register char c,f; f=1;
    while(!isdigit(c=pick())&&(c^-1)&&(c^45));
    if(c==-1) return EOF;
    if(c==45) c=pick(),f=0;
    for(x=c-48;isdigit(c=pick());(x=((x<<3)+(x<<1)))+=c-48);
    t=f?x:-x;return 1;
}
ll a[MAXN],b[MAXN],n,m;
ll sum1[MAXN],sum2[MAXN];
ll c[MAXN],d[MAXN]; 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("stdin.txt","r",stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ssb=cin.rdbuf();
    sb=cout.rdbuf();
    while(~read(n)){
        rep(i,1,n) read(a[i]);
        read(m);
        rep(i,1,m) read(b[i]);
        int cur1=1,cur2=1;
        int lo=1;
        rep(i,1,n) sum1[i]=sum1[i-1]+a[i];
        rep(i,1,m) sum2[i]=sum2[i-1]+b[i];
        cur2=lower_bound(sum2+1,sum2+1+m,a[1])-sum2;
        int ans=0;
        if(sum2[cur2]==a[1]) lo++,cur1++,cur2++,ans++;
        while(cur1<=n&&cur2<=m){
            ll tmp=sum1[cur1]-sum1[lo-1];
            ll tmp2=sum2[cur2-1];
            int pos=lower_bound(sum2+1,sum2+m+1,tmp2+tmp)-sum2;
            if(sum2[pos]==tmp2+tmp){
                cur1++;
                ans++;
                cur2=pos+1;
                lo=cur1;
            }else{
                cur1++;
            }
        }
        int mx=-1;
        if(cur1==n+1&&cur2==m+1&&sum1[n]==sum2[m]){
            mx=max(mx,ans); 
        }
        
        rep(i,1,n) c[i]=a[i];
        rep(i,1,m) d[i]=b[i];
        rep(i,1,n) swap(b[i],c[i]);
        rep(i,1,m) swap(d[i],a[i]); 
        swap(n,m);
        
        cur1=1,cur2=1;
        lo=1;
        rep(i,1,n) sum1[i]=sum1[i-1]+a[i];
        rep(i,1,m) sum2[i]=sum2[i-1]+b[i];
        cur2=lower_bound(sum2+1,sum2+1+m,a[1])-sum2;
        ans=0;
        if(sum2[cur2]==a[1]) lo++,cur1++,cur2++,ans++;
        while(cur1<=n&&cur2<=m){
            ll tmp=sum1[cur1]-sum1[lo-1];
            ll tmp2=sum2[cur2-1];
            int pos=lower_bound(sum2+1,sum2+m+1,tmp2+tmp)-sum2;
            if(sum2[pos]==tmp2+tmp){
                cur1++;
                ans++;
                cur2=pos+1;
                lo=cur1;
            }else{
                cur1++;
            }
        }
        if(cur1==n+1&&cur2==m+1&&sum1[n]==sum2[m]){
            mx=max(mx,ans);
        }
        println(mx);
    }
    flush();
    return 0; 
}