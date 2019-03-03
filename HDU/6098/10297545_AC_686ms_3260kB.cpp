#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
const int maxn = 1e5;
typedef long long ll;
//ll gcd(ll a,ll b){
//	return b==0?a:gcd(b,a%b);
//}
struct qwert{
	ll v,p;
};
bool cmp(qwert a,qwert b){
	return a.v>b.v;
}
qwert a[maxn];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof a);
		int n; scanf("%d",&n);
		for(int i = 1; i <= n; i++){
			scanf("%lld",&a[i].v);
			a[i].p=i;
		}
		sort(a+1,a+n+1,cmp);
		for(int i = 2; i <= n; i++){
			for(int j = 1; j <= n; j++){
//				if(i > a[j].p || (i< a[j].p &&gcd((long long)i,a[j].p)==1){
				if(a[j].p%i!=0){
					if(i!=n) printf("%lld ",a[j].v);
					else printf("%lld\n",a[j].v);
//					printf("%lld\n",a[j].v);
					break;
				}
			}
		}
	}
	return 0;
}