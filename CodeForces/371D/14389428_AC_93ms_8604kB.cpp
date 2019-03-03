#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 2e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
} 
int p[MAXN],a[MAXN],b[MAXN];
int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}
int main(){
    int n,m;
    while(cin>>n){
        rep(i,1,n) a[i]=read(),p[i]=i;p[n+1]=n+1;
        memset(b,0,sizeof b);
        m=read();
        rep(i,1,m){
            int op=read();
            if(op==1){
                int k=read();
                int v=read();
                while(v){
                    // if(k>n) break; //p[x]:满的相连
                    // if(b[k]+v<a[k]){
                    //     b[k]+=v;
                    //     v=0;
                    // }else{
                    //     v-=(a[k]-b[k]);
                    //     b[k]=a[k];
                    //     int x=find(k+1);
                    //     if(x==n+1)break;
                    //     if(b[x]<a[x]){//p[x]==x
                    //         p[k]=x-1;
					// 		k=x;
                    //     }else{
                    //         p[k]=x;
                    //         k=x+1;
                    //     }
                    // } //神奇的TLE..

                    // p[x]:根节点为未满的点,其余为满点
                    if(k>n) break;
                    if(b[k]+v<a[k]){
                        b[k]+=v;
                        v=0;
                    }else{
                        v-=(a[k]-b[k]);
                        b[k]=a[k];
                        int x=find(k+1);
                        if(x==n+1)break;
                        p[k]=x;k=x;
                    }
                }
            }else{
                println(b[read()]);
            }
        }
    }
    return 0;
}