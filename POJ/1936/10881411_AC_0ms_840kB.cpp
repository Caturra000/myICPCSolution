#include<iostream>
#include<algorithm> 
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+11;
char P[maxn],T[maxn];
int main(){
	while(scanf("%s%s",P,T)!=EOF){
		int len=strlen(P),cur=0;
		for(int i = 0; T[i]; i++){
			if(P[cur]==T[i]) cur++;
			if(cur==len) break;
		}
		if(cur==len) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}