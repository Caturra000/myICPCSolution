#include<bits/stdc++.h>
#include<unordered_map>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define erep(i,u) for(int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e6+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
const ll MOD = 1e9+7;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
unordered_map<int,int> mp;
int main(){ 
    while(cin>>n){
        mp.clear();
        rep(i,1,n) mp[read()]++;
        int t=0;
        unordered_map<int,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++) t=max(t,(*it).second);
        println(n-t);
    }
    return 0;
} 