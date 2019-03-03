#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e6+11;
struct Trie{
    int ch[2],sz;
}trie[maxn];
int root=1,tot=1;
void insert(int x){
    int o=root;
    trie[o].sz++;
    for(int k=30; k >= 0; k--){
        int c;
        if(x&(1<<k)) c=1;
        else c=0;
        if(!trie[o].ch[c]) trie[o].ch[c]=++tot;
        o=trie[o].ch[c];
        trie[o].sz++;
    }
}
void del(int x){
    int o=root;
    trie[o].sz--;
    for(int k = 30; k >= 0; k--){
        int c;
        if(x&(1<<k)) c=1;
        else c=0;
        o=trie[o].ch[c];
        trie[o].sz--;
    }
}
int query(int x){
    int o=root;
    for(int k = 30; k >= 0; k--){
        int c;
        if(x&(1<<k)) c=1;
        else c=0;
        if(c==1){
            if(trie[o].ch[0]&&trie[trie[o].ch[0]].sz) o=trie[o].ch[0];
            else{
                o=trie[o].ch[1];
                x^=(1<<k);
            }
        }
        else{
            if(trie[o].ch[1]&&trie[trie[o].ch[1]].sz){
                o=trie[o].ch[1];
                x^=(1<<k);
            }
            else o=trie[o].ch[0];
        }
    }
    return x;
}
int a[maxn],T,n,ans; 
int main(){
    scanf("%d",&T);
    while(T--){
        memset(trie,0,sizeof trie);
        int ans=0;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
            insert(a[i]);
        }
        for(int i = 0; i < n; i++){
            del(a[i]);
            for(int j = i+1; j < n; j++){
                del(a[j]);
                ans=max(ans,query(a[i]+a[j]));
                insert(a[j]);
            }
            insert(a[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}