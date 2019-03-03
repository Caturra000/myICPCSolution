#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
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
struct QAQ{
    ll t,cost,id;
    QAQ(){}
    QAQ(ll tt,ll cc,ll i){
        t=tt;
        cost=cc;
        id=i;
    }
    bool operator < (const QAQ &orz) const{
        return cost<orz.cost;
    }
}a[MAXN];
bool cmp(QAQ &a,QAQ &b){
    return a.t>b.t;
}
int n,T;
multiset<QAQ> mts;
vector<int> vec;
int ans;
int main(){
    while(cin>>n>>T){
        rep(i,1,n){
            int t=read();
            int cost=read();
            a[i]=QAQ(t,cost,i);
        }
        sort(a+1,a+1+n,cmp);
        mts.clear();
        vec.clear();
        ll best=0;
        int cur=1;
        ans=0;
        rrep(k,n,1){
            multiset<QAQ>::iterator it;
            while(a[cur].t>=k&&cur<=n){
                best+=a[cur].cost;
                mts.insert(a[cur]);
                cur++;
            }
            while(mts.size()>k){
                it=mts.end();--it;
                best-=(*it).cost;
                mts.erase(it);
            }
            if(mts.size()==k&&best<=T){
                ans=k;
                for(it=mts.begin();it!=mts.end();++it){
                    vec.push_back((*it).id);
                }
                break;
            }
        }
        println(ans);
        println(vec.size());
        for(int i=0;i<vec.size();i++){
            if(i==(int)vec.size()-1) println(vec[i]);
            else printbk(vec[i]);
        }
    }
    return 0;
}