#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int F[1100],a[1100],n,V;
void zeroOnePack(int F[],int C,int W){
	for(int v = V; v >= C; v--)
		F[v] = max(F[v],F[v-C]+W);
} 
int main(){
	ios::sync_with_stdio(false);
	while(cin>>n){
		if(n==0) break;
		for(int i = 0; i < n; i++)
			cin>>a[i];
		sort(a,a+n,greater<int>());
		cin>>V;
		if(V>=5){
			V-=5;
			memset(F,0,sizeof F);
			for(int i = 1; i < n; i++)
				zeroOnePack(F,a[i],a[i]);
			int mmax = 0;
			for(int i = 0; i <= V; i++) mmax = max(mmax,F[i]);
			cout<<V+5-(mmax+a[0])<<endl;
		}
		else{
			cout<<V<<endl;
		}
	}
	return 0;
}