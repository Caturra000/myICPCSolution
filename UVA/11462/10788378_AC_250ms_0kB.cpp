#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 150;
int a[maxn];
int main(){
	int n,last,x;
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		memset(a,0,sizeof a);
		last=0;
		for(int i = 0; i < n; i++){
			scanf("%d",&x);
			a[x]++;
			last=max(last,x);
		}
		for(int i = 0; i <= last; i++){
			while(a[i]){
				a[i]--;
				if(i==last&&!a[i]) printf("%d\n",i);
				else printf("%d ",i);
			}
		}
	}
	return 0;
} 