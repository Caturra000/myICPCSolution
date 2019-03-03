#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
const int maxn = 5e6+11;
typedef unsigned long long ll;
ll phi[maxn];
void euler(int n){
    for(int i = 1; i <= n; i++){
        phi[i]=i;
    }
    for(int i = 2; i <= n; i++){
        if(phi[i]==i){
            for(int j = i; j <= n; j+=i){
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}
int a,b,kase;
int main(){
    euler(int(5e6+7));
    for(int i = 1; i < maxn; i++) phi[i]=phi[i-1]+phi[i]*phi[i];
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d",&a,&b);
        printf("Case %d: %llu\n",++kase,phi[b]-phi[a-1]);
    }
    return 0;
}