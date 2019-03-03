#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
int a[10];
int SET[10];
int dfs(int left){
	if(left==1){
		rep(i,1,4) if(~SET[i]){
			return SET[i]==24;
		}
		return 0;
	}
	rep(i,1,4){
		if(SET[i]==-1)continue;
		rep(j,i+1,4){
			if(SET[j]==-1)continue;
			int a=SET[i],b=SET[j];
			SET[i]=SET[j]=-1;
			SET[i]=a+b;
			if(dfs(left-1)) return 1;
			SET[i]=a-b;
			if(dfs(left-1)) return 1;
			SET[i]=b-a;
			if(dfs(left-1)) return 1;
			SET[i]=a*b;
			if(dfs(left-1)) return 1;
			if(b&&a%b==0)SET[i]=a/b;
			if(dfs(left-1)) return 1;
			if(a&&b%a==0) SET[i]=b/a;
			if(dfs(left-1)) return 1;
			SET[i]=a;SET[j]=b;
		}
	}
	return 0;
}
char s[7][10];
int main(){
	while(cin>>s[1]>>s[2]>>s[3]>>s[4]){
		rep(i,1,4){
			if(s[i][0]=='A') a[i]=1;
			else if(s[i][0]=='J') a[i]=11;
			else if(s[i][0]=='Q') a[i]=12;
			else if(s[i][0]=='K') a[i]=13;
			else if(s[i][0]=='1'&&s[i][1]=='0') a[i]=10;
			else a[i]=s[i][0]-'0';
		}
		rep(i,1,4) SET[i]=a[i];
		memset(s,0,sizeof s);
		if(dfs(4)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
} 