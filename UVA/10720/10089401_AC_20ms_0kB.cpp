#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 4+1e4;
int v[maxn];
int main(){
	int n;
	while(scanf("%d",&n),n){
		int flag = 0;
		for(int i = 0; i < n; i++){
			scanf("%d",&v[i]);
		}
		for(int i = 0; i < n-1 && !flag; i++){
			sort(v,v+n,greater<int>());
			for(int j = i+1; j <= i+v[i]; j++)
				if(--v[j]<0) {flag = 1; break;}
		}
		if(v[n-1]!=0) flag = 1;
		if(flag) printf("Not possible\n");
		else printf("Possible\n");
	}
	return 0;
}