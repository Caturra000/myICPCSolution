#include<bits/stdc++.h>
using namespace std;
const int maxn =1e4+11;
struct Trie{
    int son[maxn],tot,root;
    int bro[maxn],sz[maxn];
    char ch[maxn];
    void init(){
        root=0;tot=1;
        son[0]=bro[0]=sz[0]=0;
        ch[0]=0;
    }
    int node(int fa,char c){
        son[tot]=0;bro[tot]=son[fa];//tot的右兄弟是未更新时fa的最后一个左儿子
        ch[tot]=c; sz[tot]=0;
        son[fa]=tot;//update
        return tot++;
    }
    void insert(char str[]){
        int now=root,lc;sz[now]++;
        for(int i = 0; str[i]; i++){
            bool flag=0;
            for(lc=son[now];lc;lc=bro[lc]){
                if(ch[lc]==str[i]){
                    flag=1;break;
                }
            }
            if(!flag){// son[now]自己和所有兄弟跑遍了 / now根本没有儿子
                lc=node(now,str[i]);
            }
            now=lc;sz[now]++;
        }
    }
    bool check(char str[]){
        int now=root,lc;
        for(int i = 0; str[i]; i++){
            for(lc = son[now]; lc; lc=bro[lc]){
                if(ch[lc]==str[i]){
                    break;
                }
            }
            if(sz[now=lc]<2) return 0; 
        }
        return 1;
    }
}trie;
char str[101][101];
int main(){
    int n=0,kase=0;
    while(scanf("%s",str[n])!=EOF){
        if(str[n][0]=='9'){
            trie.init();
            for(int i = 0; i < n; i++) trie.insert(str[i]);
            bool flag=0;
            for(int i = 0; i < n; i++){
                if(trie.check(str[i])){
                    flag=1;break;
                }
            }
            if(!flag) printf("Set %d is immediately decodable\n",++kase);
            else printf("Set %d is not immediately decodable\n",++kase);
            n=0;continue;
        }
        n++;
    }
    return 0;
}