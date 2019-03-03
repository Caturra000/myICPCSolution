#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
const int maxn = 3e6;
int p[maxn];
int maxx,n,m,a,b,cnt,pi,kase;
char str[5]; 
void init(){ 
	for(int i = 0; i < n ; i++){
		p[i]=i+n;//确保父亲都是马甲 
	}
	for(int i = n; i < maxn; i++){
		p[i]=i;
	}
//	memset(used,0,sizeof used);
	maxx=2*n;
	cnt=0;
}
int find(int x){
	return p[x]==x?p[x]:p[x]=find(p[x]);
}
void link(int a,int b){
	a=find(a);b=find(b);
	if(a!=b) p[b]=a;
}
int main(){
	while(scanf("%d%d",&n,&m),n){
		init(); 
		for(int i = 0; i < m; i++){
			scanf("%s",str);
			if(str[0]=='M'){
				scanf("%d%d",&a,&b);
				a=find(a);b=find(b);
				if(a!=b){
					link(a,b);
				}
			}
			else{
				scanf("%d",&a);
				p[a]=maxx++;
			}
		}
		map<int,int> used;
		for(int i = 0; i < n; i++){
			pi=find(i);
			if(!used[pi]){
				cnt++;
				used[pi]=1;
			}
		}
		printf("Case #%d: %d\n",++kase,cnt);
	}
	return 0;
}