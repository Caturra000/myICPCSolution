#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e4+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
bool vis[MAXN][256];
struct QAQ{
    int op;
    int v,k;
}q[MAXN];
int main(){
    int T=read();
    while(T--){
        char s[666];
        int n=read();
        rep(i,0,n+1) memset(vis[i],0,sizeof vis[i]);
        rep(i,1,n){
            scanf("%s",s);
            if(s[0]=='a'){
                q[i].op=1;
                q[i].v=read();
            }else if(s[1]=='e'){
                q[i].op=2;
                q[i].v=read();
                q[i].k=read();
            }else if(s[1]=='n'){
                q[i].op=3;
                q[i].v=read();
                q[i].k=read();
            }else if(s[1]=='l'){
                q[i].op=4;
                q[i].v=read();
                q[i].k=read();
            }else if(s[1]=='g'){
                q[i].op=5;
                q[i].v=read();
                q[i].k=read();
            }
        }
        bool flag=1,goton=0;
        int cur=0,r=0;
        while(flag&&cur!=n+1){
            if(vis[cur][r]==1){
                flag=0;
                break;
            }
            vis[cur][r]=1;
            if(cur==0){
                cur=1;
                continue;
            }
            if(q[cur].op==1){
                r=(r+q[cur].v)%256;
                cur=cur+1;
                continue;
            }
            if(q[cur].op==2){
                if(r==q[cur].v){
                    cur=q[cur].k;
                    continue;
                }
                cur=cur+1;
                continue;
            }
            if(q[cur].op==3){
                if(r!=q[cur].v){
                    cur=q[cur].k;
                    continue;
                }
                cur=cur+1;
                continue;
            }
            if(q[cur].op==4){
                if(r<q[cur].v){
                    cur=q[cur].k;
                    continue;
                }
                cur=cur+1;
                continue;
            }
            if(q[cur].op==5){
                if(r>q[cur].v){
                    cur=q[cur].k;
                    continue;
                }
                cur=cur+1;
                continue;
            }
        }
        if(cur==n+1) puts("Yes");
        else puts("No");
    }
    return 0;
}