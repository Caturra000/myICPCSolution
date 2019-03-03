#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 1e6+11;
typedef unsigned long long ll;
ll euler(int n){
    ll ans=n;
    for(ll i = 2; i*i <= n; i++){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}
vector<int> P;
void chai(int n){
    P.clear();
    for(ll i = 1; i*i <= n; i++){
        if(n%i==0){
            P.push_back(i);
            if(n/i!=i) P.push_back(n/i);
        }
    }
}
int n;
int main(){
    while(scanf("%d",&n)!=EOF){
        ll ans=0;
        chai(n);
        for(int j = 0; j < P.size(); j++){
            ans+=euler(n/P[j])*P[j];
        }
        printf("%llu\n",ans);
    }
    return 0;
}