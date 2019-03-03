#include<bits/stdc++.h>
#include<unordered_map>
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
//unordered_map<ll,ll> sum,id;
//int a[MAXN],b[MAXN];
//int main(){
//    int n;
//    while(cin>>n){
//        rep(i,1,n) b[i]=a[i]=read();
//        sum.clear();id.clear();
//        sort(b+1,b+1+n);
//        int last=b[1],st=b[1],cnt=0;
//        id[b[1]]=++cnt;
//        rep(i,2,n){
//            if(b[i]==last) continue;
//            id[last=b[i]]=++cnt;
//        }
//        ll res=0;
//        rep(j,1,n){
//            if(a[j]<=i)
//        }
//        
//    }
//}
struct FT{
    ll ft[MAXN];
    inline int lowbit(int x){
        return x&-x;
    }
    void clear(){
        memset(ft,0,sizeof ft);
    }
    void add(int k,int v){
        for(int i=k;i<MAXN;i+=lowbit(i)){
            ft[i]+=v;
        }
    }
    ll query(int R){
        ll res=0;
        for(int i=R;i;i-=lowbit(i)){
            res+=ft[i];
        }
        return res;
    }
}ft;
array<int,MAXN> a;
vector<int> vec[MAXN];
int main(){
    int n;
    while(cin>>n){
        ft.clear(); memset(vec,0,sizeof vec);
        rep(i,1,n) a[i]=min(int(read()),n);
        rep(i,1,n) vec[min(i-1,a[i])].push_back(i);
        ll res=0;
        rep(i,1,n){
            ft.add(a[i],1);
            for(int j=0;j<vec[i].size();j++){
                res+=ft.query(n)-ft.query(vec[i][j]-1);
            }
        }
        println(res);
    }
    return 0;
}