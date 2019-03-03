#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e6+4e5;
const int N = 1e8;
double tmp[N/32+7];
int main(){
    double t=0;
    for(int i = 1; i <= N; i++){
        t+=(double)1/i;
        if(i%32==0) tmp[i/32]=t;
    }
    int T,kase=0; scanf("%d",&T);
    while(T--){
        int n; scanf("%d",&n);
        int divi=n/32,remi=n%32;
        double ans=tmp[divi];
        for(int i = 1; i <= remi; i++){
            ans+=(double)1/(divi*32+i);
        }
        printf("Case %d: %.10lf\n",++kase,ans);
    }
    return 0;
}