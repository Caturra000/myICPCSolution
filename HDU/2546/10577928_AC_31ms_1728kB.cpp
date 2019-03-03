#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int F[1100],a[1100],n,V;
const int maxn = 10011;
struct qwert{
	int val,arr,task;
};

bool cmp(qwert a,qwert b){
	return a.val<b.val;
}

void zeroOnePack(int F[],int C,int W){
	for(int v = V; v >= C; v--)
		F[v] = max(F[v],F[v-C]+W);
} 
int main(){
	ios::sync_with_stdio(false);
	while(cin>>n){
		qwert ab[maxn<<1];bool vis[maxn];
		int order[maxn<<1],nn,c1,c2,val;int s[maxn<<1]; 
		if(n==0) break;
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cin>>V;
		if(V>=5){
			V-=5;
			sort(a,a+n,greater<int>());
			memset(F,0,sizeof F);
			for(int i = 1; i < n; i++)
				zeroOnePack(F,a[i],a[i]);
			cout<<V+5-(F[V]+a[0])<<endl;
		}
		else{
			cout<<V<<endl;
		}
	}
	return 0;
}