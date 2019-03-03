#include<bits/stdc++.h>
const int maxn = 4e6+11;//MaxnL
const int kd = 80;//kuandu
char s[10000];
struct Trie{
    int son[maxn][kd],end[maxn],L,root,dend[maxn];
    long long ans;
    int newnode(){
        dend[L]=end[L]=0;
        memset(son[L],-1,sizeof(son[L]));
        return L++;
    }
    void init(){
        L=ans=0;
        root=newnode();
    }
    void insert(char str[]){
        ans+=end[root];
        end[root]++;
        int now=root,index;
        for(int i = 0; str[i]; i++){
            index=str[i]-'0';
            if(son[now][index]==-1){
                son[now][index]=newnode();
            }
            now=son[now][index];
            ans+=2*end[now];
            end[now]++;
        }
        ans+=dend[now];
        dend[now]++;
    }
}trie;
int main(){
    int n,kase=0;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        trie.init();
        for(int i = 0;i < n; i++){
            scanf("%s",s);
            trie.insert(s);
        }
        printf("Case %d: %lld\n",++kase,trie.ans);
    }
    return 0;
}