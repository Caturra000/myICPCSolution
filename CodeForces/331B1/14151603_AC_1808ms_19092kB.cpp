#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e6+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll a[MAXN],pos[MAXN];
bool block[111],vis[111];
bool check(int st,int ed){
    rep(i,st,ed) if(vis[a[i]]==0)return 0;
    return 1;
}
int findlastmin(int st,int ed){
    set<int> s;
    rep(i,st,ed){
        if(!vis[a[i]]) s.insert(a[i]);
    }
    if(s.size()) return *s.begin();
    return -1;
}
int main(){
    int n,q;
    while(cin>>n){
        rep(i,1,n){
            a[i]=read();
            pos[a[i]]=i;
        }
        q=read();
        rep(i,1,q){
            int x=read();
            int y=read();
            int z=read();
            if(x==1){
//                int yy=pos[y],zz=pos[z];
//                if(yy>zz) swap(yy,zz);
//                memset(vis,0,sizeof vis);
//                rep(i,1,yy-1) vis[a[i]]=1;
//                rep(i,zz+1,n) vis[a[i]]=1;
//                int last,res=0;
//                while(1){
//                    bool fflag=0;
//                    if(check(yy,zz)) break;
//                    bool flag=0;
//                    last=findlastmin(yy,zz)-1;
////                	cout<<last<<endl;
//                    rep(i,yy,zz){
//                        //if(a[i]>max(y,z)) vis[a[i]]=1;
//                        //if(a[i]<min(y,z)) vis[a[i]]=1;
//                        if(vis[a[i]]) continue;
//                        if(a[i]==last+1){
//                            vis[a[i]]=1,last++;
//                            if(flag==0){
//                                flag=1;
//                                res++;
//                            }
//                            if(vis[y]&&vis[z]) fflag=1;
//                            if(fflag) break;
//                        }
//                    }
//                    if(fflag) break;
//                }
                ll res=0;
                ll last=y-1;
                while(1){
                    if(last>=z)break;
                    res++;
                    rep(i,1,n){
                        if(last+1==a[i])last++;
                    }
                }
                println(res);
            }else{
                int yy=a[y],zz=a[z];
                swap(a[y],a[z]);
                swap(pos[yy],pos[zz]);
            }
        }
    }
    return 0;
}