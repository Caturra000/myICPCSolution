#include<iostream>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
using namespace std;
const int maxn = 100;
map<string,int> mp;
struct edge{
	int to,cost;
};
vector<edge> G[maxn];
string str,str1,str2;
double rate,unit=1;
double d[maxn][maxn],d2[maxn][maxn];
int n,cnt,flag,kase,m;
void floyd(){
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				d2[i][j] = max(d2[i][j],d2[i][k]*d2[k][j]);
}
int main(){
	ios::sync_with_stdio(false);
	while(cin>>n){
		if(n==0) break;
		cnt=0;flag=0;memset(d,0,sizeof d);mp.clear();
		for(int i = 0; i < n; i++){
			cin>>str;
			int *mp1 = &mp[str];
			if(*mp1==0) *mp1=cnt++;
		}
		cin>>m;
		for(int i = 0; i < m; i++){
			cin>>str1>>rate>>str2;
			d[mp[str1]][mp[str2]]=rate;
//			d[mp[str2]][mp[str1]]=unit/rate;
			if(str1==str2&&rate>1.0) flag = 1;
		}
		if(flag) cout<<"Case "<<++kase<<": Yes"<<endl;
		else{
			memcpy(d2,d,sizeof d); for(int i = 0; i < n; i++) d[i][i]=unit;
			floyd();
			for(int i = 0; i < n; i++){
				if(d2[i][i]>d[i][i]){
					flag = 1;
					break;
				}
			}
			if(flag) cout<<"Case "<<++kase<<": Yes"<<endl;
			else cout<<"Case "<<++kase<<": No"<<endl;
		}
	}
	return 0;
}