#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
map<int,vector<int> > M;

int main(){
	int n,m,t;
	while(scanf("%d%d",&n,&m)!=EOF){
		M.clear();
		for(int i = 1; i <= n; i++){
			scanf("%d",&t);
			M[t].push_back(i);
		}
		int pos,num;
		for(int i = 0; i < m; i++){
			scanf("%d%d",&pos,&num);
			if(M[num].size()<pos) printf("0\n");
			else printf("%d\n",M[num][pos-1]);
		}
	}
	return 0;
}