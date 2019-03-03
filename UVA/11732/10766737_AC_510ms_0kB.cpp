#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 4e6+11;
struct Trie{
    int lson[maxn],rbro[maxn],cover[maxn],end[maxn];
    char ch[maxn];
    int cnt,root;
    long long ans;
    int newnode(const int &fa,const char &c){
        rbro[cnt]=lson[fa];
        lson[cnt]=-1;
        ch[cnt]=c;
        cover[cnt]=end[cnt]=0;
        lson[fa]=cnt;
        return cnt++;
    }
    void init(){
        ans=cnt=root=0;
        rbro[cnt]=lson[cnt]=-1;
        end[cnt]=cover[cnt]=ch[cnt]=0;
        cnt++;
    }
    void insert(char str[]){
        ans+=cover[root];
        cover[root]++;
        int now=root,i,j;
        for(i = 0; str[i]; i++){
            for(j = lson[now]; ~j; j=rbro[j]){
                if(str[i]==ch[j]){
                    break;
                }
            }
            if(j==-1) j=newnode(now,str[i]);
            now = j;
            ans+=2*cover[now];
            ++cover[now];
        }
        ans+=end[now];
        ++end[now];
    }
}trie;
char s[maxn];
int main(){
    int n,kase=0;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        trie.init();
        for(int i = 0; i < n; i++){
            scanf("%s",s);
            trie.insert(s);
        }
        printf("Case %d: %lld\n",++kase,trie.ans);
    }
    return 0;
}