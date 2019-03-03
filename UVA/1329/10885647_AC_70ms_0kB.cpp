#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+11;
struct UF{
	int p[maxn],r[maxn];
	void init(){
		for(int i = 0; i < maxn; i++) p[i]=i;
		memset(r,0,sizeof r);
	}
	int find(int x){
		if(p[x]!=x){
			int root=find(p[x]);
			r[x]+=r[p[x]];
			return p[x]=root;
		}
		else return x;
	}
	void link(int a,int b){
		p[a]=b;
		r[a]=abs(a-b)%1000;
	}
}uf;
int n,a,b;
char str[111];
int main(){
	ios::sync_with_stdio(0);
	int T; cin>>T;
	while(T--){
		cin>>n;uf.init();
		while(cin>>str&&str[0]!='O'){
			if(str[0]=='E'){
				cin>>a;
				uf.find(a);
				cout<<uf.r[a]<<endl; 
			}
			else{
				cin>>a>>b;
				uf.link(a,b);
			}
		}
	}
	return 0;
}