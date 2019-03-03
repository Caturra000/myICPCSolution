#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int maxn = 1e6+11;
const int MOD = 1e6;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    int n,l,r,tmp,now;
    ll ans;
    while(cin>>l>>r){
        n=r;
        tmp=n;
        ans=0;
        now=2;
        while(1){
            if(n/now==0)break;
            ans+=n/now;
            n-=n/now;
            now++;
        }
        ll ans1=tmp-ans;
        
        n=l-1;
        tmp=n;
        ans=0;
        now=2;
        while(1){
            if(n/now==0)break;
            ans+=n/now;
            n-=n/now;
            now++;
        }
        ll ans2=tmp-ans;
        cout<<ans1-ans2<<endl;
    }
    return 0;
}