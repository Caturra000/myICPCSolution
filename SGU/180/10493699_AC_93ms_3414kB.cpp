#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define lowbit(b) (b)&(-b)
using namespace std;
const int maxn = 1e5;
typedef long long ll;
ll ft[maxn],b[maxn],n;
struct qwert{
    ll val,pos;
    bool operator < (const qwert& that)const{
    	return val<that.val;
	}
}a[maxn];
bool cmp(qwert a,qwert b){
    return a.val<b.val;
}
ll rsq(ll b){
    ll sum = 0;
    while(b){
        sum+=ft[b];
        b-=lowbit(b);
    }
    return sum;
}
void update(ll k,ll v){
    while(k<maxn){
        ft[k]+=v;
        k+=lowbit(k);
    }
}
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n){
        memset(ft,0,sizeof ft);
        memset(a,0,sizeof a);
        for(int i = 0; i < n; i++){
            cin>>a[i].val; a[i].pos=i;
        }
        sort(a,a+n,cmp);
        for(int i = 0; i < n; i++){
            b[a[i].pos]=lower_bound(a,a+n,a[i])-a;
            b[a[i].pos]++;
        }
        ll sum = 0;
        for(int i = 0; i < n; i++){
            update(b[i],1);
            sum+=rsq(maxn-1)-rsq(b[i]);
        }
        cout<<sum<<endl;
    }
    return 0;
}