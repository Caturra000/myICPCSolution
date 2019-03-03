#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+11;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int v[maxn],w[maxn];
struct node{
	double t;
	int id;
	bool operator <(const node& b)const{
		return t>b.t;
	}
}a[maxn];
int n,k;
bool C(double x){
	double sum=0;
	for(int i = 0; i < n; i++){
		a[i].t=v[i]-x*w[i];
		a[i].id=i;
	}
	sort(a,a+n);
	for(int i = 0; i < k; i++){
		sum+=a[i].t;
	}
	return sum>=0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0); 
	while(cin>>n>>k){
		for(int i = 0; i < n; i++) cin>>v[i]>>w[i];
		double l = 0, r = INF, mid; 
		while(r-l>1e-6){
			mid=(l+r)/2;
			if(C(mid)) l=mid;//+1
			else r=mid;//-1
		}
		for(int i = 0; i < k-1; i++) cout<<a[i].id+1<<" ";cout<<a[k-1].id+1<<endl; 
	}
	return 0;
}