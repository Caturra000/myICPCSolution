#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e6+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
typedef pair<ll,ll> P;
map<ll,P> mp;
ll a[MAXN],n,sum[MAXN];
int main(){
    while(cin>>n){
        memset(sum,0,sizeof sum);
        mp.clear();
        rep(i,1,n){
            a[i]=read();
            if(a[i]>0) sum[i]=sum[i-1]+a[i];
            else sum[i]=sum[i-1];
            if(mp.count(a[i])==0){
                P tmp=P(i,-1);
                mp[a[i]]=tmp;
            }else{
                P tmp=mp[a[i]];
                tmp.second=i;
                mp[a[i]]=tmp;
            } 
        }
        map<ll,P>::iterator it;
        ll res=1ll<<60,st,ed; res=-res;
        for(it=mp.begin();it!=mp.end();it++){
//			cout<<(*it).first<<" "<<(*it).second.first<<" "<<(*it).second.second<<endl;
            P tmp=(*it).second;
            if(tmp.second==-1) continue;
//			cout<<"in"<<endl;
            ll t=sum[tmp.second-1]-sum[tmp.first]+a[tmp.first]+a[tmp.second];
//			cout<<t<<endl;
//			cout<<sum[tmp.second-1]<<" "<<sum[tmp.first]<<endl;
            if(t>res){
                res=t;
                st=tmp.first;
                ed=tmp.second;
            }
        }
        vector<ll> vec;
        rep(i,1,n){
            if(i==st||i==ed) continue;
            if(a[i]<0||i<st||i>ed) vec.push_back(i);
        }
        sort(vec.begin(),vec.end());
        printf("%lld %lld\n",res,(ll)vec.size());
        for(int i=0;i<vec.size();i++){
            if(i==(int)vec.size()-1) println(vec[i]);
            else printf("%lld ",vec[i]);
        }
    }
    return 0;
}
