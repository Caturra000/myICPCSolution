#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 503;
int r,c,cnt;
vector<int> G[maxn];
bool check[maxn];
int match[maxn];
void init(){
    memset(G,0,sizeof G);
    memset(match,-1,sizeof match);
    cnt = 0;
} 
bool dfs(int u){
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(check[v]) continue;
        check[v] = 1;
        if(match[v]==-1||dfs(match[v])){
            match[u]=v;
            match[v]=u;
            return 1;
        } 
    }
    return 0;
}
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        init();
        for(int i = 0; i < k; i++){
            scanf("%d%d",&r,&c);
            G[r].push_back(c);
            G[c].push_back(r);//
        }
        for(int i = 1; i <= n; i++){
            memset(check,0,sizeof check);
            if(match[i]==-1&&dfs(i)) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0; 
}