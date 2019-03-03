#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int maxn = 1e6+11;
const int MOD = 1e6;
typedef long long ll;
typedef __int128 big;
int n,k;
void out(big a){
    if(!a) return;
    out(a/10);
    register char ch=(a%10)+'0';
    putchar(ch);
}
int main(){
    int T,kase=0; scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        big ans=1;
        rrep(i,n,n-k+1){
            ans=ans*(big)i*(big)i;
        }
        big ans2=1;
        rep(i,1,k){
            ans2=ans2*(big)i;
        }
        big ans3=ans/ans2;
        printf("Case %d: ",++kase);
        if(ans3==0){printf("0\n");}
        else {out(ans3);putchar('\n');}
    }
    return 0;
}