#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 1e4;
int p[maxn];
int n,m;
struct edge{
    int from,to,cost;
}e;
vector<edge> G; 
bool cmp(edge a,edge b){
    return a.cost<b.cost;
}
int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}
int Scan()     //输入外挂
{
    int res=0,ch,flag=0;
    if((ch=getchar())=='-')
        flag=1;
    else if(ch>='0'&&ch<='9')
        res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+ch-'0';
    return flag?-res:res;
}
int main(){
    //ios::sync_with_stdio(false);
    while(scanf("%d%d",&n,&m)&&n+m){
    	G.clear();
        for(int i = 0; i < m; i++){
            e.from = Scan();
            e.to = Scan();
            e.cost = Scan();
            G.push_back(e);
        }
        int ans=1<<20;
        sort(G.begin(),G.end(),cmp);
        for(int i = 0; i < m; i++){ //L
			int cnt = 0, mmax = 0;
            for(int j = 0; j <= n; j++) p[j] = j;
            for(int j = i; j < m && cnt < n-1; j++){ //R
                int u = G[j].from, v = G[j].to;
                int fu = find(u), fv = find(v);
                if(fu!=fv){
                    cnt++;
                    p[fu] = fv;
                    if(j>i || m==1) mmax = G[j].cost;
                }
            }
            if(cnt==n-1) ans = min(ans,mmax-G[i].cost);
        }
        if(ans==1<<20) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}