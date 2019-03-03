#include<bits/stdc++.h>
using namespace std;
const int maxn = 15;
char G[maxn][maxn];
int main(){
	int T,kase=0; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int i = 0; i < n; i++){
			scanf("%s",G[i]);
		}
		set<char> s;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(G[i][j]!='.') continue;
				s.clear();
				if(i>0) s.insert(G[i-1][j]);
				if(i<n-1) s.insert(G[i+1][j]);
				if(j>0) s.insert(G[i][j-1]);
				if(j<n-1) s.insert(G[i][j+1]);
				for(int k = 'A'; k <= 'Z'; k++){
					if(!s.count(k)){
						G[i][j]=k;break;	
					}
				}
			}
		}
		printf("Case %d:\n",++kase);
		for(int i = 0; i < n; i++){
			printf("%s\n",G[i]);
		}
	} 
	return 0;
}