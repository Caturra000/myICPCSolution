#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int MAXN = 2e6+11;
const int MOD = 20071027;
char str[MAXN>>1],s[MAXN>>1];
int dp[MAXN>>1];
struct Trie{
    int son[MAXN],bro[MAXN],tot,root;
    char val[MAXN];
    int sz[MAXN];
    int isword[MAXN];
    void init(){
        memset(son,-1,sizeof son);
        root=0;tot=1;
        val[root]=0;sz[root]=0;isword[root]=0;
    }
    int node(int fa,char ch){
        bro[tot]=son[fa]; son[fa]=tot;//yuanlaide diyige zuoerzi bianwei youxiongdi
        val[tot]=ch; sz[tot]=0; isword[tot]=0; // son[tot]=-1; 
        return tot++;
    }
    void insert(char str[]){
        int now=0,lc=-1;
        for(int i=0;str[i];i++){
            bool flag=0;
            for(lc=son[now];~lc;lc=bro[lc]){
                if(val[lc]==str[i]){
                    flag=1;break;
                }
            }
            if(!flag) lc=node(now,str[i]);
            now=lc;sz[now]++;
        }
        isword[now]++;
    }
    int find(int from,int to){
        int now=0,lc=-1,ans=0;
        for(int i=from;i<to;i++){
            bool flag=0;
            for(lc=son[now];~lc;lc=bro[lc]){
                if(val[lc]==str[i]){
                    flag=1;
                    if(isword[lc])  ans=(ans+dp[i+1])%MOD;
                    now=lc;
                    break;
                }
            }
            if(!flag) break;
        }
        return ans;
    }
}trie;
int main(){
    int kase=0;
    while(~scanf("%s",str)){
        trie.init();
        int n; scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            trie.insert(s);
        }
        int len=strlen(str);
        memset(dp,0,sizeof dp);
        dp[len]=1;//!!!
        for(int i=len-1;i>=0;i--){
            int tmp=trie.find(i,len);
            dp[i]=tmp;
        }
        printf("Case %d: %d\n",++kase,dp[0]);
    }
    return 0;
}