#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
const int maxn = 1e5+7;
int p[maxn],r[maxn],f[maxn];
int maxx,n,m,a,b,cnt,pi,kase,cur;
//char str1[30],str2[30];
string str1,str2;
map<string,int> mc; 
inline void init(){
	mc.clear();
	for(int i = 1; i < maxn; i++) p[i]=i,f[i]=1;
	memset(r,0,sizeof r);
	cur = 1;
	str1.resize(30);
	str2.resize(30);
}
inline int find(int x){
	return p[x]==x?p[x]:find(p[x]);
}
inline void link(int a,int b){
	a=find(a);b=find(b);
	if(a==b) return ;
	if(r[a]<r[b]) p[a]=b,f[b]+=f[a];
	else{
		p[b]=a;f[a]+=f[b];
		if(r[a]==r[b]) r[a]++;
	}
}
int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			init();
			scanf("%d",&m);
			for(int i = 0; i < m; i++){
				scanf("%s%s",&str1[0],&str2[0]);
				int *ms1=&mc[str1],*ms2=&mc[str2];
				if(*ms1==0) *ms1=cur++;
				if(*ms2==0) *ms2=cur++;
				//cout<<*ms1<<" "<<*ms2<<endl;
				a=find(*ms1);b=find(*ms2);
				link(a,b);
				printf("%d\n",f[r[a]>r[b]?a:b]);
			}
		}
	}
	return 0;
}