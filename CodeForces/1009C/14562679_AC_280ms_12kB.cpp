#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m;
    while(cin>>n>>m){
        ll res=0;
        while(m--){
            ll x,d;
            cin>>x>>d;
            res+=x*n;
            if(d==0||n==1) continue;
            if(d>0){
                ll sum=n*(n-1)/2*d;
                res+=sum;
            }else if(n&1){
                ll mid=(n+1)/2;
                res+=mid*(mid-1)*d;
            }else{
                ll mid=n/2;
                res+=mid*(mid-1)*d;
                res+=n/2*d;
            }
        }
        printf("%.10lf\n",(double)res/n);
    }
    return 0;
} 