#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e4+100, INF = 0x3f3f3f3f;
int n,a[maxn];
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(a,0,sizeof a);
		for(int i = 0; i < n; i++) scanf("%d",&a[i]);
		int cnt = 0,pos = -1;
		for(int i = 0; i < n; i++){
			if(a[i]==1){
				pos=i;cnt++;break;
			}
		}
		if(pos==-1){
			printf("0\n");
			continue;
		}
		int pprev = pos;
		for(int i = pos+1; i < n; i++){
			if(a[i]==1){
				if(i-pprev>1){
					pprev = i;
					cnt+=2;
				}
				else{
					pprev=i;
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}