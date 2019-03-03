#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 1e5+1e2; 
typedef long long ll;
struct node{
	ll a,b;
}x[maxn];
bool cmp(node q,node w){
	if(q.b!=w.b) return q.b<w.b;
	return q.a<w.a;
}
ll mmax,n;
int main(){
	while(scanf("%lld",&n)!=EOF){
		for(int i = 0; i < n; i++){
			scanf("%lld%lld",&x[i].b,&x[i].a);
		}
		sort(x,x+n,cmp);mmax=0;
		for(int i = 0; i < n; i++){
			if(mmax<=x[i].a) mmax=x[i].a;
			else mmax = x[i].b;
		}
		printf("%lld\n",mmax);
	}
	return 0;
}