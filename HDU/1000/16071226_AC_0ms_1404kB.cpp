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
char IObuf[BUFL];
char *optr=IObuf;
streambuf *sb;
inline void print(char c){
    optr==IObuf+BUFL?(sb->sputn(IObuf,BUFL),optr=IObuf):0;
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
    sb->sputn(IObuf,optr-IObuf);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("stdin.txt","r",stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sb=cout.rdbuf();
    ll a,b;
    while(cin>>a>>b){
        print(a+b);
        print('\n');
    }
    flush();
    return 0;
}