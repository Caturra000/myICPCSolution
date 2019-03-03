#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
typedef long long ll;
using namespace std;
const int MAXN = 1e6+11;
ll read(){
   ll x=0,f=1;register char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
   return x*f;
}
char str[MAXN];
struct PT{
    char s[MAXN];
    int last,cur,tot;
    int son[MAXN][26];
    int fail[MAXN],len[MAXN];
    void init(){
        s[0]=-1;
        last=cur=0;
        tot=1;
        rep(i,0,25) son[0][i]=son[1][i]=0;
        len[0]=0,len[1]=-1;
        fail[0]=1;fail[1]=0;
    }
    int node(int l){
        ++tot;
        rep(i,0,25) son[tot][i]=0;
        fail[tot]=0;
        len[tot]=l;
        return tot;
    }
    int getfail(int x){
        while(s[cur-len[x]-1]^s[cur]) x=fail[x];
        return x;
    }
    void add(int pos){
        s[++cur]=str[pos];
        int t=getfail(last);
        int c=str[pos]-'a';
        if(son[t][c]==0){
            int o=node(len[t]+2);
            fail[o]=son[getfail(fail[t])][c];//....
            son[t][c]=o;
        }
        last=son[t][c];
    }
}pt;
int main(){
    while(~scanf("%s",str+1)){
        pt.init();
        int cur=0;
        while(str[++cur]) pt.add(cur);
        println(pt.tot-1);
    }
    return 0;
}