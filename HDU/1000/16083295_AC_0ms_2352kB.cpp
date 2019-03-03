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
char Obuf[BUFL];
char *optr=Obuf;
streambuf *sb,*ssb;
inline void print(char c){
    optr==Obuf+BUFL?(sb->sputn(Obuf,BUFL),optr=Obuf):0;
    *optr++=c;
}

template<class T>
inline void print(T x){
    if(x==0) {print(char(48));return;}
    if(x<0){print(char('-'));x=-x;}
    static char buf[233];
    register int cnt;
    for(cnt=0;x;x/=10) buf[++cnt]=x%10|48;
    while(cnt) print(buf[cnt--]);
}
inline void flush(){
    sb->sputn(Obuf,optr-Obuf);
}
char Ibuf[BUFL];
char *ist=NULL,*ied=NULL;
inline char _read(){
    return ist==ied?ied=Ibuf+ssb->sgetn(ist=Ibuf,BUFL),(ist==ied?-1:*(ist++)):*(ist++);
}
template<class T>
inline int read(T &t){
    ll x,c,f=1;
    while(!isdigit(c=_read())&&(c^-1)&&(c^45));
    if(c==-1) return EOF;
    if(c==45) c=_read(),f=0;
    for(x=c-48;isdigit(c=_read());(x=((x<<3)+(x<<1)))+=c-48);
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
        print(a+b);
        print('\n');
    }
    flush();
    return 0;
}