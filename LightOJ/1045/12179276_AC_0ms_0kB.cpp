#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+11;
double tmp[maxn];
int main(){
    for(int i = 1; i < maxn; i++){
        tmp[i]=tmp[i-1]+log(i);
    }
    int T,kase=0; scanf("%d",&T);
    while(T--){
        int n,k; scanf("%d%d",&n,&k);
        long long ans=tmp[n]/log(k)+1;
        printf("Case %d: %lld\n",++kase,ans);
    }
    return 0;
}