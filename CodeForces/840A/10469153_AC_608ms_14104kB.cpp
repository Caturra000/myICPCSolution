#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 3e5+100, INF = 0x3f3f3f3f;
typedef long long ll;
ll n; 
struct qwert{
	ll val,pos,c;
}a[maxn],b[maxn];
bool cmp(qwert a,qwert b){
	if(a.val!=b.val){
		return a.val<b.val;
	}
	return a.pos>b.pos;
}
bool cmp3(qwert a,qwert b){
	if(a.val!=b.val){
		return a.val>b.val;
	}
	return a.pos>b.pos;
}
bool cmp2(qwert a,qwert b){
	return a.pos<b.pos;
}
int main(){
	ios::sync_with_stdio(false);
	while(cin>>n){
		for(int i = 0; i < n; i++){
			cin>>a[i].val;
			a[i].pos=i;
		}
		for(int i = 0; i < n; i++){
			cin>>b[i].val;
			b[i].pos=i;
		}
		sort(a,a+n,cmp3);
		sort(b,b+n,cmp);
		for(int i = 0; i < n; i++) b[i].c=a[i].val;
		sort(b,b+n,cmp2);
		for(int i = 0; i < n; i++){
			if(i!=n-1) cout<<b[i].c<<" ";
			else cout<<b[i].c<<endl;
		}
	}
	return 0;
}