#include<bits/stdc++.h>
using namespace std;
int n,kase;
int main(){
	while(scanf("%d",&n)!=EOF){
		if(n<1) break;
		printf("Case %d: %d\n",++kase,(int)ceil(log2(n)));
	}
	return 0;
} 