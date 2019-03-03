#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+11;
typedef long long ll;
int chai(int n,int base){
	int cnt=0;
	while(n){
		if(n%base==0){
			n/=base;cnt++;
		}
		else break;
	}
	return cnt;
}
int _2[maxn],_5[maxn];
void init(){
	_2[0]=_2[1]=0;
	_5[0]=_5[1]=0;
	for(int i = 2; i < maxn; i++){
		_2[i]=_2[i-1]+chai(i,2);
		_5[i]=_5[i-1]+chai(i,5);
	}
}
int main(){
	init();
	int T,kase=0; scanf("%d",&T);
	while(T--){
		int n,r,p,q; scanf("%d%d%d%d",&n,&r,&p,&q);
		ll _22=_2[n]-_2[r]-_2[n-r];
		ll _55=_5[n]-_5[r]-_5[n-r];
		ll p1=1ll*chai(p,2)*q,p2=1ll*chai(p,5)*q;
		printf("Case %d: %d\n",++kase,min(_22+p1,_55+p2));
	}
	return 0;
}