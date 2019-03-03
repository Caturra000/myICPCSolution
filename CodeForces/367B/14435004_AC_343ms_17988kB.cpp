#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 2e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll a[MAXN],b[MAXN],n,m,p;
map<ll,ll> mp[2];
int main(){
    while(cin>>n>>m>>p){
        rep(i,1,n) a[i]=read();
        rep(i,1,m) b[i]=read();
        rep(i,0,1) mp[i].clear();
        rep(i,1,m) mp[0][b[i]]++;
        set<int> s;
        rep(i,1,p){
            mp[1].clear();
            int last=i;
            int cur=i;
            int cnt=0;
            while(cur<=n){
                cnt++;
                mp[1][a[cur]]++;
                if(cnt>=m){
//                    cout<<"match: "<<endl;
//                    for(map<ll,ll>::iterator it=mp[1].begin();it!=mp[1].end();it++){
//                        cout<<(*it).first<<" "<<(*it).second<<endl;
//                    }
//                    cout<<endl<<endl;
                    if(mp[1]==mp[0]){
                        s.insert(last);
                    }
                    mp[1][a[last]]--;
                    if(mp[1][a[last]]==0) mp[1].erase(a[last]);
                    last+=p;
                }
                cur+=p;
            }
        }
        println(s.size());
        set<int>::iterator it=s.begin();
        for(int i=0;i<s.size();i++){
            if(i==(int)s.size()-1) cout<<*it<<endl;
            else cout<<*it<<" ";
            it++;
        }
    }
    return 0;
}