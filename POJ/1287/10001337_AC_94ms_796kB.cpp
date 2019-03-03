#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 1e3;
struct edge{
    int from,to;
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
    	cin >> m;
    	G.clear();
        for(int i = 0; i < m; i++){
            cin>>e.from>>e.to>>e.cost;
            G.push_back(e);
        }
        sort(G.begin(),G.end(),cmp);
        int cnt = 0, ans = 0;
        for(int i = 0; i <= n; i++){
            p[i] = i;
        }
        for(int i = 0; i < G.size(); i++){
            int u = G[i].from, v = G[i].to;
            int fu = find(u), fv = find(v);
            if(fu!=fv){
                //cnt++;
                p[fu] = fv;
                ans += G[i].cost;
            }
        }
        cout << ans << endl;
    }
    return 0; 
}
