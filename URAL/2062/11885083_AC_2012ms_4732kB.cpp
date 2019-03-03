#include<bits/stdc++.h>
using namespace std;
const int maxn = 4e5+11;
typedef long long ll;
struct FT{
    ll ft[maxn];
    void init(){memset(ft,0,sizeof ft);}
    inline int lowbit(int b){return b&(-b);}
    void add(int k,int v){
        for(int i=k; i < maxn; i+=lowbit(i)){
            ft[i]+=v;
        }
    }
    inline void add(int l,int r,int v){
        add(l,v);add(r+1,-v);
    }
    ll rsq(int k){
        ll sum=0;
        for(int i = k; i; i-=lowbit(i)){
            sum+=ft[i];
        }
        return sum;
    }
}ft;
int n,m,op,k,l,r,a[maxn];
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        ft.init();
        for(int i = 1; i <= m; i++){
            scanf("%d",&op);
            if(op==1){
                scanf("%d",&k);
                ll sum=a[k];
                for(int j = 1; j*j <= k; j++){
                    // cout<<k<<" "<<j<<" "<<k%j<<" "<<k/j<<endl;
                    if(k%j==0){
                        sum+=ft.rsq(j);
                        if(k/j!=j) sum+=ft.rsq(k/j);//cout<<"test"<<k/j<<endl;
                    }
                }
                printf("%lld\n",sum);
            }
            else{
                scanf("%d%d%d",&l,&r,&k);
                 ft.add(l,r,k);
            }
        }
    }
    return 0;
}