#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int maxn = 1e5+11;
const int oo = 0x3f3f3f3f;
typedef pair<int,int> P;
char str[666][666];
int n,m;
int main(){
    ios::sync_with_stdio(0);
    while(cin>>n>>m){
        rep(i,1,n) cin>>str[i]+1;
        int tot=0;
        int a=oo,b=-oo,c=oo,d=-oo;
        rep(i,1,n) rep(j,1,m){
            if(str[i][j]=='X'){
                a=min(a,i);
                b=max(b,i);
                c=min(c,j);
                d=max(d,j);
                tot++;
            }
        }
        // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        if((b-a+1)*(d-c+1)==tot) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}