#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 10111;
struct qwert{
	int val,arr,task;
}a[maxn<<1];
bool vis[maxn];
int order[maxn<<1],n,c1,c2,val;
bool cmp(qwert a,qwert b){
	return a.val<b.val;
}
int s[maxn<<1]; 
int main(){
	ios::sync_with_stdio(false);
	while(cin>>n){
		if(n==0) break; 
		memset(a,0,sizeof a);memset(vis,0,sizeof vis);memset(order,0,sizeof order);memset(s,0,sizeof s);c1=0;c2=0;
		for(int i = 0; i < n; i++){
			cin>>a[2*i].val;a[2*i].arr=1;a[2*i].task=i;  s[i]=a[2*i].val;
			cin>>a[2*i+1].val;a[2*i+1].arr=2;a[2*i+1].task=i;  s[i+n]=a[2*i+1].val;
		}
		sort(a,a+2*n,cmp);
		for(int i = 0; i < 2*n; i++){
			if(vis[a[i].task]) continue;
			vis[a[i].task]=1;
			if(a[i].arr==1){
				order[c1++]=i;
			}
			else{
				order[n-1-c2++]=i;
			}
		}
		int sum = 0;
//		for(int i = 0; i < n; i++) cout<<a[order[i]].task<<" ";cout<<endl;//ok 
		int atime=0,btime=0;
		for(int i = 0; i < n; i++){
			atime+=s[a[order[i]].task];
			btime=max(btime,atime)+s[a[order[i]].task+n];
		}
		cout<<btime<<endl; 
	}
	return 0;
}