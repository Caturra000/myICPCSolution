#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
using namespace std;
typedef long long ll;
const int maxn  = 1e5+11;
ll xxor[maxn],aand[maxn],oor[maxn];
ll qian[maxn],hou[maxn];
int a[maxn],n,q;
int main(){
    while(scanf("%d%d",&n,&q)!=EOF){
        rep(i,1,n) scanf("%d",&a[i]);
        
        ll t=a[1];
        rep(i,2,n) t^=a[i]; 
        rep(i,1,n) xxor[i]=t^a[i];


        qian[1]=a[1];
        rep(i,2,n) qian[i]=qian[i-1]&a[i];
        hou[n]=a[n];
        rrep(i,n-1,1) hou[i]=hou[i+1]&a[i];
        rep(i,2,n-1) aand[i]=qian[i-1]&hou[i+1];
        aand[1]=hou[2];aand[n]=qian[n-1];
        
        
        qian[1]=a[1];
        rep(i,2,n) qian[i]=qian[i-1]|a[i];
        hou[n]=a[n];
        rrep(i,n-1,1) hou[i]=hou[i+1]|a[i];
        rep(i,2,n-1) oor[i]=qian[i-1]|hou[i+1];
        oor[1]=hou[2];oor[n]=qian[n-1];
        
        rep(i,1,q){
            scanf("%lld",&t);
            printf("%d %d %d\n",aand[t],oor[t],xxor[t]);
        }
    }
    return 0;
}
