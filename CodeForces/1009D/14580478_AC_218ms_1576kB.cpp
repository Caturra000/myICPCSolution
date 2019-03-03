#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define erep(i,u) for(int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e3+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
const ll MOD = 1e9+7;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
typedef pair<int,int> P;
vector<P> vec;
int main(){
    int n,m;
    while(cin>>n>>m){
        vec.clear();
        if(m<n-1){
            cout<<"Impossible"<<endl;
            continue;
        }
        rep(i,1,n){
            rep(j,i+1,n){
                if(vec.size()>=m) break;
                if(gcd(i,j)==1) vec.push_back(P(i,j));
            }
        }
        if(vec.size()>=m){
            cout<<"Possible"<<endl; 
            for(int i=0;i<vec.size();i++){
                cout<<vec[i].first<<" "<<vec[i].second<<endl;
            }
        }else{
            cout<<"Impossible"<<endl; 
        }
    }
    return 0;
}