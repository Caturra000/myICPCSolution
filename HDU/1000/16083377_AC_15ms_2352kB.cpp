#pragma GCC diagnostic error "-std=c++11"
#include<ext/pb_ds/priority_queue.hpp>
#include<bits/stdc++.h>
#define unordered_map map
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
const int MAXN = 1e5+11;
const int INF  = 0x3f3f3f3f; 
/********************************************/
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
/********************************************/
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