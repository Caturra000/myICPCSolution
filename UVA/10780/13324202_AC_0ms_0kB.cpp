#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<sstream>
#include<vector>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
using namespace std;
const int maxn = 1e5+11;
typedef long long ll;
int n,m;
vector<int> p,k;
void chai(int n){
    p.clear();k.clear();
    int t=n;
    for(int i=2;i*i<=n;i++){
        if(t%i==0){
            p.push_back(i);
            k.push_back(1);
            t/=i;
            int pos=k.size()-1;
            while(t%i==0){
                k[pos]++;
                t/=i;
            }
        }
    }
    if(t>1) p.push_back(t),k.push_back(1);
}
int main(){
    int T,kase=0; cin>>T;
    while(T--){
        scanf("%d%d",&m,&n);
        chai(m);
        ll ans=1ll<<61;
        for(int i=0;i<p.size();i++){
            ll tmp=n,t=0;
            while(tmp>1){
                t+=tmp/p[i];
                tmp/=p[i];
            }
            ans=min(t/k[i],ans);
        }
        cout<<"Case "<<++kase<<":"<<endl;
        if(!ans) cout<<"Impossible to divide"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
