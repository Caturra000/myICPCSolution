#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
typedef long long ll;
using namespace std;
const int MAXN = 1e6+11;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll ooo= 0x3f3f3f3f;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,sz;
struct VEC{
    vector<int> vec;
    VEC(){vec.clear();}
    ~VEC(){vec.clear();}
    bool operator < (const VEC &rhs) const{
        return vec.size()>rhs.vec.size();
    }
    
};
vector<VEC> vec;
ll check(int x){
    bool flag=0;
    ll res=0; 
    int y=x-sz;
    int cnt=0;
    priority_queue<int,vector<int>,greater<int> > que; 
    rep(i,0,m-2){
        if(vec[i].vec.size()>=x){
            int tt=vec[i].vec.size()-x;
            for(int j=0;j<vec[i].vec.size();j++){
                if(j<=tt) res+=vec[i].vec[j],cnt++;
                else que.push(vec[i].vec[j]);
            }
        }else for(int j=0;j<vec[i].vec.size();j++){
            que.push(vec[i].vec[j]);
        }
    }
    if(cnt>=x) return res;
    y-=cnt;
    while(y--){
        if(que.empty()){
            flag=1;
            break;
        }
        res+=que.top();que.pop();
    }
    if(flag) return 1ll<<60;
    return res;
}
int main(){
    while(cin>>n>>m){
        vec.clear();
        vec.resize(m-1);
        sz=0;
        rep(i,1,n){
            int p=read();
            int c=read();
            if(p==1) sz++; 
            else vec[p-2].vec.push_back(c);
        }
        rep(i,0,m-2) sort(vec[i].vec.begin(),vec[i].vec.end());
        sort(vec.begin(),vec.end());
        ll res=1ll<<60;
        rep(i,1,n) res=min(res,check(i));
        println(res);
    }
    return 0;
}