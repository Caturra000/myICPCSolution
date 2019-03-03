#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
const int MAXN = 5e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct Trie{
    int son[MAXN*30][2],size[MAXN*30][2][2];
    ll cnt[1<<5][2];
    int tot,root;
    void init(){
        root=tot=1;
        rep(i,0,1)rep(j,0,1)size[tot][i][j]=0;
        son[tot][0]=son[tot][1]=0;
        memset(cnt,0,sizeof cnt);
    }
    void insert(int val){
        int o=root;
        rrep(i,29,0){
            int wh=val>>i&1;
            if(son[o][wh]==0){
                son[o][wh]=++tot;
                rep(ii,0,1)rep(j,0,1) size[tot][ii][j]=0;
                rep(ii,0,1) son[tot][ii]=0;
            }
            size[o][wh][1]++;//set: 0 left 1 right
            o=son[o][wh];
        }
    }
    ll query(int val){
        int o=root;
        ll res=0;
        rrep(i,29,0){
            int wh=val>>i&1;
            res+=cnt[i][wh];
            cnt[i][wh]+=size[o][wh^1][1];//!!!
            cnt[i][wh^1]-=size[o][wh^1][0];
            size[o][wh][1]--;
            size[o][wh][0]++;
            o=son[o][wh];
        }
        return res;
    }
}trie;
int a[MAXN];
int main(){
    int T=read();
    while(T--){
        int n=read();
        rep(i,1,n) a[i]=read();
        trie.init();
        rep(i,1,n) trie.insert(a[i]);
        ll res=0;
        rep(i,1,n) res+=trie.query(a[i]);
        println(res);
    }
    return 0;
}