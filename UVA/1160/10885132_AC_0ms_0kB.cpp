#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
struct UF{
	int p[maxn];
	void init(){
		for(int i = 0; i < maxn; i++) p[i]=i;
	}
	int find(int x){
		return p[x]==x?x:p[x]=find(p[x]);
	}
	void link(int a,int b){
		a=find(a);b=find(b);
		if(a!=b) p[a]=b;
	}
	bool same(int a,int b){
		return find(a)==find(b);
	}
}uf; 
int main(){
	ios::sync_with_stdio(0);
	int a,b,cnt=0;uf.init();
	while(cin>>a){
		if(a==-1){
			printf("%d\n",cnt);
			cnt=0;uf.init();
			continue;
		}
		cin>>b;
		if(uf.same(a,b)) cnt++;
		else uf.link(a,b);
	}
	return 0;
}