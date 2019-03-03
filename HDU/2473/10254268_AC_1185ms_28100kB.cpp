#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 3e6;
int p[maxn],r[maxn];//,pos[maxn];
int maxx,n,m,a,b,cnt,pi,kase;
bool used[maxn];
char str[5]; 
void init(){
	for(int i = 0; i < n ; i++){
		p[i]=i+n;
	}
	for(int i = n; i < maxn; i++){
		p[i]=i;
	}
	memset(used,0,sizeof used);
	memset(r,0,sizeof r); 
	maxx=2*n;
	cnt=0;
}
int find(int x){
	return p[x]==x?p[x]:p[x]=find(p[x]);
}
void link(int a,int b){
	a=find(a);b=find(b);
	if(a==b) return;
	if(r[a]<r[b]){
		p[a]=b;
	}
	else{
		p[b]=a;
		if(r[a]==r[b]) r[a]++;
	}
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