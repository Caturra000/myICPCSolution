#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e6+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
set<ll> s,edge;
bool vis[MAXN];
int bfs(int n){
    queue<ll> que;
    set<ll>::iterator it=s.begin();
    que.push(*it);s.erase(it);
    int res=1;
    while(!que.empty()){
        ll u=que.front();
        vis[u]=1;
        que.pop();
        for(it=s.begin();it!=s.end();){
            if(!edge.count(u*n+(*it))){
                res++;
                que.push(*it);
                s.erase(it++);
            }else it++;
        }
    }
    return res;
}
int main(){
    int n,m;
    while(cin>>n>>m){
        memset(vis,0,sizeof vis);
        s.clear();edge.clear();
        rep(i,1,m){
            ll u=read();
            ll v=read();
            edge.insert(u*n+v);
            edge.insert(u+v*n);
        }
        rep(i,1,n) s.insert(i);
        vector<int> vec;
        while(!s.empty()){
            int t=bfs(n);
            vec.push_back(t);
        }
        //cout<<"ok"<<endl;
        println(vec.size());
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            if(i==(int)vec.size()-1) println(vec[i]);
            else printf("%d ",vec[i]);
        }
    }
    return 0;
}