#include<iostream>
using namespace std;
const int maxn = 1e6+11;;
typedef unsigned long long ll;
bool isnprime[maxn];
int prime[maxn];
ll phi[maxn];
int sai(int n){
    isnprime[0]=isnprime[1]=1;
    for(int i = 2; i*i <= n; i++){
        if(!isnprime[i]){
            for(int j = 2*i; j <= n; j+=i){
                isnprime[j]=1;
            }
        }
    }
    int cnt=0;
    for(int i = 1; i <= n; i++) if(!isnprime[i]) prime[cnt++]=i;
    return cnt;
}
void euler(int n,int pn){
    for(int i = 1; i <= n; i++) phi[i]=i;
    for(int i = 0; i < pn; i++){
        for(int j = prime[i]; j <= n; j+=prime[i]){
            phi[j]=phi[j]/prime[i]*(prime[i]-1);
        }
    }
//  for(int i = 1; i <= n; i++) cout<<i<<" "<<phi[i]<<endl; 
}
ll sum[maxn],t;
int main(){
    ios::sync_with_stdio(0);
    int cnt=sai(int(1e6+7));
    euler(int(1e6+7),cnt);
    for(int i = 1; i < maxn; i++) sum[i]=sum[i-1]+phi[i];
    while(cin>>t){
        if(t==0)break;
        cout<<sum[t]-1<<endl;
    }
    return 0;
}