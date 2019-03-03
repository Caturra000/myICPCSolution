#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
typedef long long ll;
using namespace std;
const int MAXN = 2e6+11;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll ooo= 0x3f3f3f3f;
ll read(){
   ll x=0,f=1;register char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
   return x*f;
}
struct AHO{
    int cnt[MAXN];
    int fail[MAXN];
    int son[MAXN][26];
    int tot,root;
    void init(){
        tot=root=1;
        cnt[root]=fail[root]=0;
        rep(i,0,25) son[root][i]=0;
    }
    int node(){
        ++tot;
        cnt[tot]=fail[tot]=0;
        rep(i,0,25) son[tot][i]=0;
        return tot;
    }
    void insert(char *str){
        int o=root;
        int len=strlen(str+1);
        rep(i,1,len){
            int c=str[i]-'a';
            if(son[o][c]==0){
                son[o][c]=node();
            }
            o=son[o][c];
        }
        cnt[o]++;
    }
    void build(){
        queue<int> que;
        que.push(root);
        while(!que.empty()){
            int o=que.front();
            que.pop();
            rep(i,0,25){
                if(!son[o][i]) continue;
                if(o==root) fail[son[o][i]]=root;
                else{
                    int t=fail[o]; //zuichangqianzhui yu fuqin youguan
                    while(t){
                        if(son[t][i]){// if exists
                            fail[son[o][i]]=son[t][i];
                            break;
                        }
                        t=fail[t];
                    }
                    if(t==0) fail[son[o][i]]=root;
                }
                que.push(son[o][i]);
            }
        }
    }
    int query(char *str){
        int len=strlen(str+1);
        int o=root;
        int res=0;
        rep(i,1,len){
            int c=str[i]-'a';
            while(son[o][c]==0&&o!=root) o=fail[o];
            o=son[o][c];
            if(o==0) o=root;
            int t=o;
            while(t!=root){
                if(cnt[t]>=0){
                    res+=cnt[t];
                    cnt[t]=-1;
                }else break;
                t=fail[t];
            }
        }
        return res;
    }
}aho;
char str[MAXN];
int main(){
    int T=read();
    while(T--){
        aho.init();
        int n=read();
        rep(i,1,n){
            scanf("%s",str+1);
            aho.insert(str);
        }
        aho.build();
        scanf("%s",str+1);
        println(aho.query(str));
    }
    return 0;
}