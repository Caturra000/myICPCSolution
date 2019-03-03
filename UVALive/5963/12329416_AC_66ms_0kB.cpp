#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int maxn = 1e6+11;
const int MOD = 1e6;
typedef long long ll;
int a[maxn],b[maxn],book[maxn],tmp[maxn];
int main(){
    ios::sync_with_stdio(0);
    int T,kase=0; cin>>T;
    while(T--){
        int n;cin>>n;
        rep(i,1,n) cin>>tmp[i];
        sort(tmp+1,tmp+1+n);
        rep(i,1,n) a[i]=n-tmp[i],b[i]=1+tmp[i];
        memset(book,0,sizeof book);
        rep(i,1,n) book[a[i]]++,book[b[i]]++;
        bool flag=0;
        rep(i,1,n) if(book[i]!=2) flag=1;
        if(flag) cout<<"Case "<<++kase<<": "<<"no"<<endl;
        else cout<<"Case "<<++kase<<": "<<"yes"<<endl;
    }
    return 0;
}