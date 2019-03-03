#include<bits/stdc++.h>
using namespace std;
#define lowbit(b) (b)&(-b)
#define rr register
const int maxn = 1e6+11;
struct FT{
    int ft[maxn];
    void init(){
        memset(ft,0,sizeof ft);
    }
    int query(int b){
        int sum=0;
        while(b){
            sum+=ft[b];
            b-=lowbit(b);
        }
        return sum;
    }
    void update(int k,int v){
        while(k<maxn){
            ft[k]+=v;
            k+=lowbit(k);
        }
    }
}ft;
bool C(int x,int tmp){
    int sum=ft.query(x);
    return sum>=tmp+1;
}
int ans[maxn];
int main(){
    ios::sync_with_stdio(0);
    rr int T,k; cin>>T;
    while(T--){
        ft.init();cin>>k;
        for(rr int i = 1; i <= k; i++) ft.update(i,1);
        for(rr int i = 1; i <= k; i++){
            rr int tmp; cin>>tmp;
            rr int l=1,r=k,mid;
            while(l<r){
                mid=l+r>>1;
                if(C(mid,tmp)) r=mid;
                else l=mid+1;
            }
            ans[i]=l;ft.update(ans[i],-1);
        }
        for(rr int i = 1; i <= k; i++){
            if(i==k) cout<<ans[i]<<endl;
            else cout<<ans[i]<<" ";
        }
    }
    return 0;
}