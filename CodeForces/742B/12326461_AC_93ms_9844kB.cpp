#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int maxn = 1e6+11;
const int oo = 0x3f3f3f3f;
typedef long long ll;
ll n,m,x,a[maxn],t;
int main(){
    ios::sync_with_stdio(0);
    while(cin>>n>>x){
        memset(a,0,sizeof a);
        ll ans=0;
        rep(i,1,n){
            cin>>t;
            ans+=a[t^x];
            a[t]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}