#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
using namespace std;
typedef long long ll;
const int maxn  = 1e6+11;
const int N = 1e6;
int num[maxn],n,q;
int main(){
    while(scanf("%d",&n)!=EOF){
        memset(num,0,sizeof num);
        int cnt=0,t;
        rep(i,1,n) {scanf("%d",&t);num[t]++;}
        rep(i,1,N){
            if(num[i]>=2){
                cnt+=(num[i]/2);
                num[i]%=2;
            }
            if(i>N-2)continue;
            if(num[i]==1&&num[i+1]%2==1&&num[i+2]){//%2
                num[i]--;num[i+1]--;num[i+2]--;
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
