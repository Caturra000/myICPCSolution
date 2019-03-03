#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
int a[10];
double SET[10];
const double eps=1e-6;
int dfs(int left){
	if(left==1){
		rep(i,1,4) if(SET[i]!=-1){
			return fabs(SET[i]-24)<eps;
		}
		return 0;
	}
	rep(i,1,4) if(SET[i]!=-1){
		rep(j,i+1,4) if(SET[j]!=-1){
			double a=SET[i],b=SET[j];
			SET[i]=SET[j]=-1;
			SET[i]=a+b;
			if(dfs(left-1)) return 1;
			SET[i]=a-b;
			if(dfs(left-1)) return 1;
			SET[i]=b-a;
			if(dfs(left-1)) return 1;
			SET[i]=a*b;
			if(dfs(left-1)) return 1;
			if(b) SET[i]=a/b;
			if(dfs(left-1)) return 1;
			if(a) SET[i]=b/a;
			if(dfs(left-1)) return 1;
			SET[i]=a;SET[j]=b;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	int T; cin>>T;
	while(T--){
		cin>>SET[1]>>SET[2]>>SET[3]>>SET[4];
		if(dfs(4)) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
} 