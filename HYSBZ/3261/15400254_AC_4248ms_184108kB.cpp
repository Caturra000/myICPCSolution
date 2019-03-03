#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iter(i,j) for(int i=0;i<(j).size();i++)
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 6e5+11;
const int oo = 0x3f3f3f3f;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T[MAXN],a[MAXN],b[MAXN];
struct TRIE{
    int tot;
    int son[MAXN*25][2],size[MAXN*25];
    void init(){
        tot=0;
        son[0][0]=son[0][1]=size[0]=0;
        memset(T,0,sizeof T);
    }
    int insert(int old,int val){
        int rt,o;rt=o=++tot;
        rrep(i,23,0){
            son[o][0]=son[old][0],
            son[o][1]=son[old][1];
            size[o]=size[old]+1;
            int wh=val>>i&1;
            son[o][wh]=++tot;
            old=son[old][wh];
            o=son[o][wh];
        }
        size[o]=size[old]+1;
        return rt;
    }
    int query(int l,int r,int val){
        int ans=0;
        rrep(i,23,0){
            int wh=val>>i&1;
            if(size[son[r][wh^1]]-size[son[l][wh^1]]){
                ans|=(1<<i),r=son[r][wh^1],l=son[l][wh^1];
            }else{
                r=son[r][wh],
                l=son[l][wh];
            }
        }
        return ans;
    }
}trie;
int main(){
    int n,m;
    while(cin>>n>>m){
        trie.init();
        n++;
        a[1]=0;
        rep(i,2,n) a[i]=read();
        rep(i,1,n) b[i]=b[i-1]^a[i];
        rep(i,1,n) T[i]=trie.insert(T[i-1],b[i]);
        char str[55];
        int l,r,x;
        while(m--){
            scanf("%s",str+1);
            if(str[1]=='A'){
                n++;
                a[n]=read();
                b[n]=b[n-1]^a[n];
                T[n]=trie.insert(T[n-1],b[n]);
            }else{
                l=read();
                r=read();
                x=read();
                println(trie.query(T[l-1],T[r],b[n]^x));
            }
        }
    }
    return 0;
}