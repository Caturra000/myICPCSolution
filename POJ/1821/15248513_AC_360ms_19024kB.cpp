#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iter(i,j) for(int i=0;i<(j).size();i++)
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 2e4+11;
const int oo = 0x3f3f3f3f;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct XJB{
    int l,p,s;
    bool operator < (const XJB &r) const{
        return s<r.s;
    }
}a[MAXN];
int n,m;
int f[233][MAXN];
inline int cal(int i,int k){
    return f[i-1][k]-a[i].p*k;
}
int main(){
    while(cin>>n>>m){
        rep(i,1,m){
            a[i].l=read();
            a[i].p=read();
            a[i].s=read();
        }
        sort(a+1,a+1+m);
        memset(f,0,sizeof f);
        deque<int> que;
        rep(i,1,m){
            while(!que.empty()) que.pop_back();
            rep(k,max(0,a[i].s-a[i].l),a[i].s-1){ //j-Li<=k<=Si-1,j>=Si
                while(!que.empty()&&cal(i,k)>=cal(i,que.back())) que.pop_back();
                que.push_back(k);
            }
            rep(j,1,n){
                f[i][j]=max(f[i][j],f[i-1][j]);
                f[i][j]=max(f[i-1][j],f[i][j-1]);
                if(j>=a[i].s){
                    while(!que.empty()&&que.front()<j-a[i].l) que.pop_front();
                    if(!que.empty()) f[i][j]=max(f[i][j],cal(i,que.front())+a[i].p*j);
                }
            }
        }
        println(f[m][n]);
    }
    return 0;
}