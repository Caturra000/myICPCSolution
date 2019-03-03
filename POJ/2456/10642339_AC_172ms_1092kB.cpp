#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+11;
const int INF = 0x3f3f3f3f;
int a[maxn],n,m;
bool C(int d){
	int last=0;//cow0
	for(int i = 1; i < m; i++){
		int cur=last+1;
		while(cur<n&&a[cur]-a[last]<d) cur++;
		if(cur==n) return 0;
		last=cur;
	}
	return 1;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i = 0; i < n; i++){
			scanf("%d",&a[i]);	
		}
		sort(a,a+n);
		int l = 0, r = a[n-1]-a[0], mid, ans;
		for(int i = 0; i < 100; i++){
			mid = (l+r)>>1;
			if(C(mid)) l=mid+1;
			else r=mid-1;
//			cout<<l<<" "<<r<<" "<<mid<<endl; 
		}
		printf("%d\n",r);
	}
	return 0;
}