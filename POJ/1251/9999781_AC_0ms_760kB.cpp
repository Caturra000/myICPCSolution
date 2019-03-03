#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 1e3;
struct edge{
    char from,to;
    int cost;
}e;
bool cmp(edge a,edge b){
    return a.cost<b.cost;
}
vector<edge> G;
int p[maxn];
int find(int x){
    return x==p[x]?x:p[x]=find(p[x]);
}
int n,m,from,to,cost;
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n&&n){
    	G.clear();
        for(int i = 0; i < n-1; i++){
            //scanf("%d%d",&e.from,&m);
            cin>>e.from>>m;
            for(int j = 0; j < m; j++){
                //scanf("%d%d",&e.to,&e.cost);
                cin>>e.to>>e.cost;
                G.push_back(e);
            }
        }
        sort(G.begin(),G.end(),cmp);
        int cnt = 0, ans = 0;
        for(int i = 0; i < n; i++){
            p[i] = i;
        }
        for(int i = 0; i < G.size() && cnt < n; i++){
            int u = G[i].from-'A', v = G[i].to-'A';
            int fu = find(u), fv = find(v);
            if(fu!=fv){
                cnt++;
                p[fu] = fv;
                ans += G[i].cost;
            }
        }
        cout << ans << endl;
    }
    return 0; 
}
