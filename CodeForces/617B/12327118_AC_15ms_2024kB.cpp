#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int maxn = 1e3+11;
const int oo = 0x3f3f3f3f;
typedef long long ll;
int n,m,x,a[maxn],t;
int main(){
    ios::sync_with_stdio(0);
    while(cin>>n){
        int tot=0;
        rep(i,1,n){cin>>a[i];tot+=a[i];}
        if(tot==0){
            cout<<0<<endl;
            continue;
        }
        ll ans=1;
        int _0=0;
        bool first=0;
        rep(i,1,n){
            if(a[i]==1){
                if(first==0){
                    first=1;
                    _0=0;
                    continue;
                }
                ans*=(_0+1);
                _0=0;
            }
            else{
                _0++;
            }
        }
        // if(_0) ans*=_0;
        cout<<ans<<endl;
    }
    return 0;
}